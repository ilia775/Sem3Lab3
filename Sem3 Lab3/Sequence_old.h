#pragma once
#include <iostream>
using namespace std;

template <typename T> class DynamicArray
{
public:
    DynamicArray(int size)
    {
        this->arr = new T[size];
        this->len = size;
    }
    DynamicArray()
    {
        len = 0;
        arr = new T[len];
    }
    DynamicArray(T* items, int count)
    {
        /*if (arr != nullptr)
        {
            delete[] arr;
            len = count;
        }*/
        arr = new T[count];
        len = count;
        for (int i = 0; i < len; i++)
        {
            arr[i] = items[i];
        }
    }

    DynamicArray(const DynamicArray<T>& other)
    {
        this->len = other.len;
        this->arr = new T[this->len];
        for (int i = 0; i < this->len; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    T* GetArr()
    {
        return arr;
    }

    T& Get(int index)
    {
        if (index < len) return arr[index];
        else throw "IndexOutOfRange_DA_Get";
        //else cout << "IndexOutOfRange_DA_Get\n";
        return arr[0];
    }
    T GetLast()
    {
        try {
            return this->Get(len - 1);
        }
        catch (string ex)
        {
            throw ex;
        }
    }
    T GetFirst()
    {
        try {
            return this->Get(0);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetSize()
    {
        return len;
    }

    void Set(int index, T item)
    {
        if (index < len) arr[index] = item;
        else throw "IndexOutOfRange";
    }

    void Resize(int NewSize)
    {
        T* arrnew = new T[NewSize]();
        if (NewSize >= len)
        {
            for (int i = 0; i < len; i++)
            {
                arrnew[i] = arr[i];
            }

        }
        else
        {
            for (int i = 0; i < NewSize; i++)
            {
                arrnew[i] = arr[i];
            }
        }
        len = NewSize;
        delete[] arr;
        this->arr = arrnew;
    }

    DynamicArray<T> operator=(const DynamicArray<T>& other)
    {
        T* arrnew = new T[other.len];
        for (int i = 0; i < other.len; i++)
        {
            arrnew[i] = other.arr[i];
        }
        delete[] arr;
        len = other.len;
        this->arr = arrnew;
        return DynamicArray<T>(*this);
    }



    ~DynamicArray()
    {
        delete[] this->arr;
    }

    void Print(int index)
    {
        cout << arr[index] << endl;
    }

    T& operator[](int index)
    {
        if (index < len) return arr[index];
        else throw "IndexOutOfRange_DA_[]";
        return arr[0];
    }

private:
    T* arr;
    int len;
};

template <typename T> class LinkedList
{
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    ~LinkedList()
    {
        while (size)
        {
            this->Pop_Front();
        }
    }

    LinkedList(T* items, int count)
    {
        size = 0;
        //head = new Node<T>();
        for (int i = 0; i < count; i++)
        {
            this->Push_Back(items[i]);
        }
    }

    LinkedList(int count)
    {
        size = 0;
        head = nullptr;
        /*head = new Node<T>();
        Node<T>* temp = head;
        for (int i = 0; i < count - 1; i++)
        {
            temp = temp->ptrNext;
            temp = new Node<T>();
        }*/
        for (int i = 0; i < count; i++)
        {
            this->Push_Back(T());
        }
    }

    LinkedList(const LinkedList<T>& other)
    {
        Node<T>* temp = other.head;
        for (int i = 0; i < other.size; i++)
        {
            this->Push_Back(temp->data);
            temp = temp->ptrNext;
        }
    }

    T GetFirst()
    {
        if (size >= 1)
        {
            try {
                return this->Get(0);
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        else
        {
            throw "IndexOutOfRange_LL_GetFirst";
            //return T();
        }
    }

    void Resize(int NewSize)
    {
        if (NewSize == size) {}
        else if (NewSize > size) for (int i = 0; i < NewSize - size;) this->Append(T());
        else if (NewSize < size) for (int i = 0; i < size - NewSize;) this->Pop_Back();
    }

    /*void Remove(int index)
    {

        Node<T>* res = this->head;
        bool removed = 0;
        for (int i = 0; i < this->GetSize(); i++)
        {
            if (i == index)
            {
                removed = 1;
            }
            else
            {

            }
        }
    }*/

    T GetLast()
    {
        if (size == 0)
        {
            throw "IndexOutOfRange_LL_GetLast";
            return T();
        }
        else
        {
            try
            {
                return this->Get(size - 1);
            }
            catch (string ex)
            {
                throw ex;
            }
            /*Node<T>* temp = head;
            while (temp->ptrNext != nullptr)
            {
                temp = temp->ptrNext;
            }
            return temp->data;*/
        }
    }

    T& Get(int index)
    {
        if (index < size)
        {
            return this->operator[](index);
        }
        else
        {
            throw "IndexOutOfRange_LL_Get";
            //return *(new T());
        }

    }

    //LinkedList<T>* GetRelatedSubList(int startIndex, int endIndex)
    //{
    //    if (startIndex < size && endIndex < size && startIndex >= 0 && endIndex >= 0)
    //    {
    //        if (endIndex < startIndex)
    //        {
    //            LinkedList<T>* res = new LinkedList<T>();
    //            return res;
    //        }
    //        LinkedList<T>* res = new LinkedList<T>(endIndex - startIndex + 1);
    //        Node<T>* temp = head, temp1 = res->head;
    //        //T* arrnew = new T[endIndex - startIndex + 1];
    //        for (int i = 0; i < startIndex; i++)
    //        {
    //            temp = temp->ptrNext;
    //        }
    //        for (int i = startIndex; i <= endIndex; i++)
    //        {
    //            temp1->data = &temp->data;
    //            temp1 = temp1->ptrNext;
    //            temp = temp->ptrNext;
    //        }
    //        //LinkedList<T>* res = new LinkedList<T>(arrnew, endIndex - startIndex + 1);
    //        //delete[] arrnew;
    //        return res;
    //    }
    //    else
    //    {
    //        throw "IndexOutOfRange_LL_GetSubList";
    //        LinkedList<T>* res = new LinkedList<T>();
    //        return res;
    //    }
    //}

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < size && endIndex < size && startIndex >= 0 && endIndex >= 0)
        {
            if (endIndex < startIndex)
            {
                LinkedList<T>* res = new LinkedList<T>();
                return res;
            }
            Node<T>* temp = head;
            T* arrnew = new T[endIndex - startIndex + 1];
            for (int i = 0; i < startIndex; i++)
            {
                temp = temp->ptrNext;
            }
            for (int i = startIndex; i <= endIndex; i++)
            {
                arrnew[i - startIndex] = temp->data;
                temp = temp->ptrNext;
            }
            LinkedList<T>* res = new LinkedList<T>(arrnew, endIndex - startIndex + 1);
            delete[] arrnew;
            return res;
        }
        else
        {
            throw "IndexOutOfRange_LL_GetSubList";
            LinkedList<T>* res = new LinkedList<T>();
            return res;
        }
    }

    void Clear()
    {
        while (size)
        {
            this->Pop_Front();
        }
    }

    void printall()
    {
        cout << "printall  this=" << this << endl;
        for (int i = 0; i < size; i++)
        {
            cout << this->operator[](i) << endl;
        }
    }

    void Pop_Front()
    {
        //cout << this << "   " << size << this->head->data << endl;
        Node<T>* temp = head->ptrNext;
        delete head;
        head = temp;
        size -= 1;
    }

    void Push_Back(T data)
    {
        size += 1;
        if (head == nullptr)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T>* current = this->head;
            while (current->ptrNext != nullptr)
            {
                current = current->ptrNext;
            }
            current->ptrNext = new Node<T>(data);
        }
    }

    int GetSize()
    {
        return size;
    }

    T& operator[](int index)
    {
        Node<T>* current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->ptrNext;
        }
        return current->data;
    }

    LinkedList<T>& operator=(const LinkedList<T>& other)
    {
        Clear();
        Node<T>* temp = other.head;
        for (int i = 0; i < other.size; i++)
        {
            Push_Back(temp->data);
            temp = temp->ptrNext;
        }
        return *this;
    }

    void Push_Front(T data)
    {
        head = new Node<T>(data, head);
        size += 1;
    }

    T* GetArr()
    {
        T* Arr = new T[size]();
        Node<T>* temp = this->head;
        for (int i = 0; i < size; i++)
        {
            Arr[i] = temp->data;
            temp = temp->ptrNext;
        }
        return Arr;
    }

    void Pop_Back()
    {
        Node<T>* current = this->head;
        for (int i = 0; i < size - 1; i++)
        {
            current = current->ptrNext;
        }
        delete[] current->ptrNext;
        current->ptrNext = nullptr;
        size -= 1;
    }

    void Append(T item)
    {
        Push_Back(item);
    }

    void Prepend(T item)
    {
        Push_Front(item);
    }


    void InsertAt(T item, int index)
    {
        if (index > size) throw "IndexOutOfRange_LL_InsertAt";
        else
        {

            if (index == 0)
            {
                Push_Front(item);
            }
            else {
                index -= 1;
                size += 1;
                Node<T>* temp = this->head;
                for (int i = 0; i < index; i++)
                {
                    temp = temp->ptrNext;
                }
                Node<T>* ins = new Node<T>(item, temp->ptrNext);
                temp->ptrNext = ins;
            }
        }
    }
    LinkedList<T>* Concat(LinkedList<T>* other)
    {
        size += other->size;
        Node<T>* temp = head;
        while (temp->ptrNext != nullptr)
        {
            temp = temp->ptrNext;
        }
        temp->ptrNext = other->head;
        LinkedList<T>* res = new LinkedList<T>(*this);
        return res;
    }



private:
    template <typename T1> class Node
    {
    public:
        Node<T1>* ptrNext;
        T1 data;

        Node(T1 data = T1(), Node<T1>* ptrNext = nullptr)
        {
            this->data = data;
            this->ptrNext = ptrNext;
        }
        Node<T1>& operator=(const Node<T1> other)
        {
            this->data = other.data;
        }
        /*Node<T1>& operator[](const int index)
        {
            Node<T1>* temp = this;
            for (int i = 0; i < index; i++)
            {
                temp = temp->ptrNext;
            }
            return &temp->data;
        }*/
    };
    int size;
    Node<T>* head;
};

template <typename T> class ISortedSequence
{
public:
    virtual bool contains(T value) = 0;
    virtual ~ISortedSequence() {};
    virtual T GetFirst() = 0;
    virtual void Resize(int len) = 0;
    virtual T GetLast() = 0;
    virtual T* GetArr() = 0;

    virtual T& Get(int index) = 0;
    virtual void Set(int index, T Value) = 0;
    virtual ISortedSequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;

    virtual int GetLenght() = 0;

    virtual void Append(T item) = 0;

    virtual void Remove(int index) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;

    virtual ISortedSequence <T>* Concat(ISortedSequence <T>* list) = 0;
    virtual T& operator[](int index) = 0;
    virtual void Sort() = 0;
private:
};

template <typename T> class ArraySortedSequence : public ISortedSequence<T>
{
public:
    ~ArraySortedSequence() override
    {
        delete items;
    }

    bool contains(T value)
    {
        for (int i = 0; i < this->GetSize(); i++)
        {
            if (this->Get(i) == value) return true;
        }
        return false;
    }

    void Set(int index, T Value) override
    {
        items->operator[](index) = Value;
    }

    void Sort() override // ShellSort
    {
        int i = 0, j = 0, len = this->GetLenght();
        T tmp;
        for (int step = len / 2; step > 0; step /= 2)
        {
            for (i = step; i < len; i++)
            {
                tmp = items->Get(i);
                for (j = i; j >= step; j -= step)
                {
                    if (tmp > items->Get(j - step))
                    {
                        items->Get(j) = items->Get(j - step);
                    }
                    else
                    {
                        break;
                    }
                }
                items->Get(j) = tmp;
            }
        }
    }

    ArraySortedSequence(T* items, int count)
    {
        this->items = new DynamicArray<T>(items, count);
    }
    ArraySortedSequence(const ISortedSequence<T>& other)
    {
        this->items = new DynamicArray(other->items);
    }
    ArraySortedSequence()
    {
        this->items = new DynamicArray<T>();
    }

    ArraySortedSequence(int count)
    {
        this->items = new DynamicArray<T>(count);
    }

    T& operator[](int index) override
    {
        return items->operator[](index);
    }

    int GetSize()
    {
        return this->GetLenght();
    }

    T* GetArr() override
    {
        return items->GetArr();
    }

    ISortedSequence <T>* Concat(ISortedSequence <T>* other) override
    {
        for (int i = 0; i < other->GetLenght(); i++)
        {
            try {
                this->Append(other->Get(i));
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        ArraySortedSequence<T>* res = new ArraySortedSequence<T>(*this);
        return res;
    }



    ISortedSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        DynamicArray<T>* temp = new DynamicArray<T>(abs(endIndex - startIndex) + 1);
        for (int i = startIndex; i <= endIndex; i++)
        {
            temp->operator[](i - startIndex) = items->operator[](i);
        }
        int len = temp->GetSize();
        T* arr = new T[len];
        for (int i = 0; i < len; i++)
        {
            try {
                arr[i] = temp->Get(i);
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        delete temp;
        ArraySortedSequence<T>* res = new ArraySortedSequence<T>(arr, len);
        return res;
    }

    T GetFirst() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetFirst();
        }

        else throw "IndexOutOfRange_DS_GETFIRST";
        return items->GetFirst();
    }

    T GetLast() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetLast();
        }

        else throw "IndexOutOfRange_DS_GetLast";
        return items->GetLast();
    }

    T& Get(int index) override
    {
        try
        {
            return items->Get(index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetLenght() override
    {
        return items->GetSize();
    }

    void Remove(int index) override
    {
        if (index < 0 || index >= this->GetLenght()) throw "ERROR IndexOutOfRange";
        else
        {
            bool removed = 0;
            DynamicArray<T>* nitems = new DynamicArray<T>(this->GetLenght() - 1);
            for (int i = 0; i < this->GetLenght(); i++)
            {
                if (i == index)
                {
                    removed = 1;
                }
                else
                {
                    nitems->Set(i, this->Get(i - removed));
                }
            }
            delete items;
            items = nitems;
        }
        
    }

    void Append(T item) override
    {
        //if (items->GetSize() != 0) {
        int len = items->GetSize() + 1;
        DynamicArray<T>* items_new = new DynamicArray<T>(len);
        for (int i = 0; i < len - 1; i++)
        {
            items_new->operator[](i) = items->operator[](i);
        }
        items_new->operator[](len - 1) = item;
        if (items->GetSize() != 0) delete items;
        items = items_new;
        //}
        //else throw "IndexOutOfRange_DS_APPEND";
    }

    void InsertAt(T item, int index) override
    {
        if (this->GetSize() < index) throw"IndexOutOfRange_AS_InsertAt";
        if (index == 0) this->Prepend(item);
        else if (index == items->GetSize()) this->Append(item);
        else
        {
            int len = items->GetSize() + 1;
            DynamicArray<T>* items_new = new DynamicArray<T>(len);
            int i1 = 0;
            for (int i = 0; i < len; i++)
            {
                if (i != index) {
                    items_new->operator[](i) = items->operator[](i1);
                    i1++;
                }
                else
                {
                    items_new->operator[](i) = item;
                }
            }
            delete items;
            items = items_new;
        }
    }

    void Prepend(T item) override
    {
        int len = items->GetSize() + 1;
        DynamicArray<T>* items_new = new DynamicArray<T>(len);
        items_new->operator[](0) = item;
        for (int i = 1; i < len; i++)
        {
            items_new->operator[](i) = items->operator[](i - 1);
        }
        delete items;
        this->items = items_new;
    }

    void Resize(int len) override
    {
        items->Resize(len);
    }
//private:
protected:
    DynamicArray<T>* items;
};


template <typename T> class ListSortedSequence : public ISortedSequence<T>
{
public:

    void PopFront()
    {
        items->Pop_Front();
    }

    void Sort() override
    {
        int i = 0, j = 0, step = 0, len = this->GetSize();
        T tmp;
        for (step = len / 2; step > 0; step /= 2)
        {
            for (i = step; i < len; i++)
            {
                tmp = this->Get(i);
                for (j = i; j >= step; j -= step)
                {
                    if (compare(tmp, this->Get(j - step)))
                    {
                        this->Get(j) = this->Get(j - step);
                    }
                    else
                    {
                        break;
                    }
                }
                this->Get(j) = tmp;
            }
        }
    }

    ~ListSortedSequence() override
    {
        if (items->GetSize() != 0) delete items;
    }

    ListSortedSequence(const ListSortedSequence<T>& other)
    {
        this->items = new LinkedList(other->items);
    }

    void Remove(int index) override
    {
        items->Remove(index);
    }

    ListSortedSequence(T* items, int count)
    {
        this->items = new LinkedList<T>(items, count);
    }

    ListSortedSequence(int count)
    {
        this->items = new LinkedList<T>(count);
    }

    ListSortedSequence()
    {
        this->items = new LinkedList<T>();
    }

    T* GetArr()
    {
        return items->GetArr();
    }


    int GetSize()
    {
        return this->GetLenght();
    }

    T& operator[](int index) override
    {
        return items->operator[](index);
    }
    ISortedSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        ListSortedSequence<T>* res = new ListSortedSequence<T>();
        try
        {
            res->items = this->items->GetSubList(startIndex, endIndex);
        }
        catch (string ex)
        {
            throw ex;
        }
        return res;
    }

    ISortedSequence <T>* Concat(ISortedSequence <T>* other) override
    {
        ListSortedSequence<T>* temp = new ListSortedSequence<T>(this->GetArr(), this->GetLenght());
        temp->items->Concat(new LinkedList<T>(other->GetArr(), other->GetLenght()));
        return temp;
    }

    T GetFirst() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetFirst();
        }
        else
        {
            throw "IndexOutOfRange_LS_GetFirst";
            return T();
        }
    }

    T GetLast() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetLast();
        }
        else
        {
            throw "IndexOutOfRange_DS_GetLast";
            return T();
        }
    }

    T& Get(int index) override
    {
        try
        {
            return items->Get(index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetLenght() override
    {
        return items->GetSize();
    }

    void Append(T item) override
    {
        items->Append(item);
    }

    void InsertAt(T item, int index) override
    {
        try
        {
            items->InsertAt(item, index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void Prepend(T item) override
    {
        items->Prepend(item);
    }

    void Resize(int len) override
    {
        items->Resize(len);
    }

//private:
protected:
    LinkedList<T>* items;
};
