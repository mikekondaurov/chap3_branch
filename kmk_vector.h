#include <algorithm>
#include <iterator>
#include <cstddef>


template<class T>
class Kmk_Iterator;

template<typename T>
 class Kmk_Vector {
public:
        typedef Kmk_Iterator<T> iterator;
        typedef size_t size_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;


        Kmk_Vector(){}
        explicit Kmk_Vector(const  int s);
        T& operator[](size_t i); // for non-const Vectors
        const T& operator[](const size_t i) const; // for const Vectors (§5.2.1)
        Kmk_Vector(std::initializer_list<T>);

        size_t size() ;
        ~Kmk_Vector() { delete[] elem; } // destructor: release resources
        friend bool CompareVec(Kmk_Vector<T>& v1, Kmk_Vector<T>& v2);
        void push_back(T te);

        T* begin() {
                return &elem[0];
        };
        Kmk_Iterator<T> end()
        {
                return Kmk_Iterator<T>(elem + sz);
        }

///     typedef Kmk_Vector<T> iterator;
 private:
//      double* elem; // elem points to an array of sz doubles
         T* elem;
         size_t sz{0};  // Число элементо
};

template<typename T>
Kmk_Vector<T>::Kmk_Vector(const int s)
///     :elem{ new double[s] }, sz{ s } // initialize members
{
  // инвариант конструктора определяет какие параметры правильные для класса
        if (s < 0)
          throw std::length_error{ "Vector constructor: отрицательный размер" };
        elem = new T[s];
        sz = s;
        // auto - появилось в С11
        for (auto i=0; i< sz;i++)
                elem[i] = static_cast<T>(0);
}
 template<typename T>
 Kmk_Vector<T>::Kmk_Vector(std::initializer_list<T> lst)
         :elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
 {
         copy(lst.begin(), lst.end(), elem); // copy from lst into elem (§13.5)
 }
template<typename T>
const T& Kmk_Vector<T>::operator[](const size_t i) const
{
        if ( size() <= i)
                throw std::out_of_range{ "Vector::operator[]" };
        return elem[i];
}

template<typename T>
T& Kmk_Vector<T>::operator[](size_t i)
{
        if ( size() <= i)
                throw std::out_of_range{ "Vector::operator[]" };
        return elem[i];
}

template<typename T>
size_t Kmk_Vector<T>::size()
{
        //sz = 1;
        return sz;
}
template<typename T>
void Kmk_Vector<T>::push_back(T te)
{
        T* elem_new = new T[sz+1];
        if (sz != 0) {
                std::copy(&elem[0], &elem[sz + 1], elem_new); // copy from lst into elem (§13.5)
                // свободные функции( не члены класса) std::begin   std::end появились в C11
                //      std::copy(std::begin(elem), std::end(elem), std::begin(elem_new));
                delete[]elem;
        }
//      sz++;

        elem_new[sz] = te;

        elem = elem_new;
        sz++;
}
// Функция сравнения векторов
//export  template<typename T> bool CompareVec( Vector<T>& v1,  Vector<T>& v2)
template<typename T> bool CompareVec(Kmk_Vector<T>& v1, Kmk_Vector<T>& v2)

{
        if (v1.size() != v2.size())
                return false;
        for ( int i = 0; i < v1.size(); ++i)
                if (v1[i] != v2[i])
                        return false;
        return true;
}

template<class T>
class Kmk_Iterator
{
public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::forward_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;


        Kmk_Iterator(T* curr) :current(curr)
        {
        }
        Kmk_Iterator& operator =(const Kmk_Iterator& other)
        {
                if (this != &other)
                {
                        current = other.current;
                }
                return *this;
        }
        Kmk_Iterator& operator ++()
        {
                ++current;
                return *this;
        }
        Kmk_Iterator operator ++(int i)
        {
                Kmk_Iterator tmp(current);
                ++current;
                return tmp;
        }
        T& operator *()
        {
                return *current;
        }

        T* operator ->()
        {
                return current;
        }
        bool operator ==(const Kmk_Iterator& other)
        {
                return current == other.current;
        }
        bool operator !=(const Kmk_Iterator& other)
        {
                return !(*this == other);
        }
private:
        T* current;
};



