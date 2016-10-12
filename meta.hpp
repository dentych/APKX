#pragma once


class NullType {};


template <typename T, typename U>
struct is_same {
    static const bool value = false;
};


template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};


template <typename TList, typename T>
struct contains {
    static const bool value =
         is_same<typename TList::first, T>::value
         || contains<typename TList::rest, T>::value;
};


template <typename T>
struct contains<NullType, T> {
    static const bool value = false;
};


template <typename THead, typename TList>
struct TypeList
{
    typedef THead first;
    typedef TList rest;
};


#define TYPELIST1(t1) TypeList<t1, NullType>
#define TYPELIST2(t1, t2) TypeList<t1, TYPELIST1(t2)>
#define TYPELIST3(t1, t2, t3) TypeList<t1, TYPELIST2(t2, t3)>
#define TYPELIST4(t1, t2, t3, t4) TypeList<t1, TYPELIST3(t2, t3, t4)>
#define TYPELIST5(t1, t2, t3, t4, t5) TypeList<t1, TYPELIST4(t2, t3, t4, t5)>
