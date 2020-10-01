#ifndef TEMPLATES_LIST_2020_08_06
#define TEMPLATES_LIST_2020_08_06

namespace LeafStruct
{


    template<class T>
    class CDualLinkedList
    {
    private:
        struct leaf
        {
            T data;
            leaf * pnext, *pprev;
            leaf(T& _data, leaf * _pprev = nullptr, leaf * _pnext = nullptr) 
            {
                this->data = _data;
                this->pprev = _pprev;
                this->pnext = _pnext;
            }
        };
    public:
        class CIterator
        {
        public:
            CIterator()
            {
            }

            CIterator(leaf *p)
            {
                m_pCurrent = p;
            }

            CIterator(const CIterator &src)
            {
            }

            ~CIterator()
            {

            }

            CIterator& operator = (const CIterator&  src){
                return src.m_pCurrent;
            }

            bool operator != (const CIterator&  it) const
            {
                return m_pCurrent != it.m_pCurrent;
            }

            void operator++()
            {
                m_pCurrent = m_pCurrent->pnext;
            }

            void operator--()
            {
                m_pCurrent = m_pCurrent->pprev;
            }

            T& getData()
            {
                return m_pCurrent->data;
            }

            T& operator* ()
            {
                return m_pCurrent->data;
            }

            leaf* getLeaf(){
                return m_pCurrent;
            }

            void setLeaf(leaf* p){
                m_pCurrent = p;
            }
            void setLeafPreBegin(leaf* p) {
                m_pBegin = p;
                m_pCurrent = m_pBegin->pnext;
            }
            void setLeafPostEnd(leaf* p){
                m_pEnd = p;
                m_pCurrent = m_pEnd->pprev;
            }

            bool isValid(){
                if (m_pCurrent != nullptr) {
                    return true;
                }
                else {
                    return false;
                }
            }

        private:
            // keep head of leaf, then before first element
            leaf* m_pBegin;
            // keep current element
            leaf* m_pCurrent;
            // keep tail of leaf, then after last element
            leaf* m_pEnd;
        };


    public:

        CDualLinkedList()
          {
            m_pBegin = nullptr;
            m_pEnd = nullptr;
          };

          virtual ~CDualLinkedList()
          {
          };

          void pushBack(T& data)
          {
              if (m_pBegin == nullptr) {
                  m_pBegin = new leaf(data);
                  m_pEnd = m_pBegin;
              }
              else {
                  m_pEnd->pnext = new leaf(data);
                  m_pEnd->pnext->pprev = m_pEnd;
                  m_pEnd = m_pEnd->pnext;
              }

          }
          T popBack()
          {
              if(m_pEnd->pprev != nullptr){
                  m_pEnd = m_pEnd->pprev;
                  T tdata = m_pEnd->pnext->data;
                  m_pEnd->pnext = nullptr;
                  return tdata;
              }
              else if(m_pEnd != nullptr){
                  T tdata = m_pEnd->data;
                  m_pBegin = nullptr;
                  m_pEnd = nullptr;
                  return tdata;
              }

          }

          void pushFront(T& data)
          {
              if (m_pBegin == nullptr) {
                  m_pBegin = new leaf(data);
                  m_pEnd = m_pBegin;
              }
              else {
                  m_pBegin->pprev = new leaf(data);
                  m_pBegin->pprev->pnext = m_pBegin;
                  m_pBegin = m_pBegin->pprev;
              }

          }			  
          T popFront()
          {
              if (m_pBegin->pnext != nullptr) {
                  m_pBegin = m_pBegin->pnext;
                  T tdata = m_pBegin->pprev->data;
                  m_pBegin->pprev = nullptr;
                  return tdata;
              }
              else if (m_pBegin != nullptr) {
                  T tdata = m_pBegin->data;
                  m_pBegin = nullptr;
                  m_pEnd = nullptr;
                  return tdata;
              }

          }

          // changes iterator and gives him previous point
          void erase(CIterator& it)
          {
              if (m_pBegin == nullptr) {
                  return;
              }

              if (it.getLeaf() != m_pBegin) {
                  leaf* cur = m_pBegin;
                  while (it.getLeaf() != cur) {
                      cur = cur->pnext;
                  }
                  it.setLeaf(cur->pprev);
                  if (cur != m_pEnd) {
                      cur->pprev->pnext = cur->pnext;
                      cur->pnext->pprev = cur->pprev;
                  }
                  else {
                      m_pEnd = m_pEnd->pprev;
                  }
                  cur = nullptr;
              }
              else {
                  it.setLeafPreBegin(m_pBegin);
                  m_pBegin = m_pBegin->pnext;
                  m_pBegin->pprev = nullptr;
              }
          }

          // changes iterator and gives him next point
          void eraseAndNext(CIterator& it)
          {
              if (m_pBegin == nullptr) {
                  return;
              }

              if (it.getLeaf() != m_pEnd) {
                  leaf* cur = m_pEnd;
                  while (it.getLeaf() != cur) {
                      cur = cur->pprev;
                  }
                  it.setLeaf(cur->pnext);
                  if (cur != m_pBegin) {
                      cur->pprev->pnext = cur->pnext;
                      cur->pnext->pprev = cur->pprev;
                  }
                  else {
                      m_pBegin = m_pBegin->pnext;
                  }
                  cur = nullptr;
              }
              else {
                  it.setLeafPostEnd(m_pEnd);
                  m_pEnd = m_pEnd->pprev;
                  m_pEnd->pnext = nullptr;
              }
          }      

          int getSize()
          {
              if (m_pBegin == nullptr) {
                  return 0;
              }
              leaf* cur = m_pBegin;
              int size = 0;
              while (cur != nullptr) {
                  cur = cur->pnext;
                  size++;
              }
              return size;
          }

          void clear()
          {
              if (m_pBegin == nullptr) {
                  return;
              }
              while (m_pBegin != m_pEnd) {

                  m_pEnd = m_pEnd->pprev;
                  m_pEnd->pnext = nullptr;
              }
              m_pBegin = nullptr;
              m_pEnd = nullptr;
          }

          CIterator begin()
          {
              return CIterator(m_pBegin);
          }

          CIterator end()
          {
              return CIterator(m_pEnd);
          }
    private:
        //keep first and last elements of leaf
        leaf* m_pBegin, *m_pEnd;
    };
};
#endif
