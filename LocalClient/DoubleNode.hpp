#include <string>
template<typename T>
class DoubleNode {
private:
    T *Data;
    DoubleNode<T> *Front;
    DoubleNode<T> *Back;
public:
    DoubleNode();
    ~DoubleNode();
    void setData(T &data);
    T* getData();
    void setFront(DoubleNode<T> &Node);
    void setBack(DoubleNode<T> &Node);
    DoubleNode<T>& getBack();
    DoubleNode<T>& getFront();
    bool emptyFront();
    bool emptyBack();
    void makeFrontEmpty();
    void makeBackEmpty();
};


template <typename T>
/**
 * @brief DoubleNode<T>::DoubleNode
 * Constructor
 */
DoubleNode<T>::DoubleNode()
    {
        Data=(T*)malloc(sizeof(T));
        Front=NULL;
        Back=NULL;
    }

template <typename T>
/**
 * @brief DoubleNode<T>::~DoubleNode
 *  * Constructor
 */
DoubleNode<T>::~DoubleNode()
    {
        free(Data);
        if(Front!=NULL)free(Front);
        if(Back!=NULL)free(Back);
    }

template <typename T>
/**
 * @brief DoubleNode<T>::setData
 * @param data
 * @author Adrian Gonzalez
 */
void DoubleNode<T>::setData(T &data)
    {
        *Data=data;
    }

template <typename T>
/**
 * @brief DoubleNode<T>::getData
 * @return
 * @author Adrian Gonzalez
 */
T* DoubleNode<T>::getData()
    {
        return Data;
    }

template <typename T>
/**
 * @brief DoubleNode<T>::getBack
 * @return
 */
DoubleNode<T>& DoubleNode<T>::getBack()
    {
        //if(Back==NULL)return emptyReturn;
        return *Back;
    }

template <typename T>
/**
 * @brief DoubleNode<T>::getFront
 * @return
 */
DoubleNode<T>& DoubleNode<T>::getFront()
    {
        //if(Front==NULL)return emptyReturn;
        return *Front;
    }

template <typename T>
/**
 * @brief DoubleNode<T>::setBack
 * @param Node
 */
void DoubleNode<T>::setBack(DoubleNode<T> &Node)
    {
        Back=&Node;
    }

template <typename T>
/**
 * @brief DoubleNode<T>::setFront
 * @param Node
 */
void DoubleNode<T>::setFront(DoubleNode<T> &Node) {
    Front=&Node;
}
template <typename T>
bool DoubleNode<T>::emptyBack() {
    if(Back==NULL)return true;
    return false;
}
template <typename T>
/**
 * @brief DoubleNode<T>::emptyFront
 * @return
 */
bool DoubleNode<T>::emptyFront() {
    if(Front==NULL)return true;
    return false;
}


template <typename T>
/**
 * @brief DoubleNode<T>::makeBackEmpty
 */
void DoubleNode<T>::makeBackEmpty() {
    Back=NULL;
}
template <typename T>
/**
 * @brief DoubleNode<T>::makeFrontEmpty
 */
void DoubleNode<T>::makeFrontEmpty() {
    Front==NULL;
}
