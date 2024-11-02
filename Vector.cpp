#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <cassert>

template <typename T>
class Vector {
public:
    Vector() : data_(nullptr), size_(0), place_(0) {};

    ~Vector() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        place_ = 0;
    }

    void Push_back(const T& val) {
        if (size_ == place_) {
            Resize(size_ * 2);
        }
        data_[size_] = val;
        size_++;
    }

    void Resize(size_t new_size) {
        T* new_data = new T[new_size];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        std::swap(data_, new_data);
        std::swap(place_, new_size);
    }

    void Pop_back() {
        if (size_ > 0) {
            size_--;
        }
    }

    size_t Size() const {
        return size_;
    }

    bool Empty() {
        return size_ == 0;
    }

    void Clear() {
        size_ = 0;
    }

    T& operator[](size_t ind) {
        if (ind >= size_ || ind < 0) {
            throw std::runtime_error("Incorrect ind");
        }
        return data_[ind];
    }

    const T& operator[](size_t ind) const {
        if (ind >= size_ || ind < 0) {
            throw std::runtime_error("Incorrect ind");
        }
        return data_[ind];
    }

    T& At(size_t ind) {
        if (ind >= size_ || ind < 0) {
            throw std::runtime_error("Incorrect ind");
        }
        return data_[ind];
    }

    const T& At(size_t ind) const {
        if (ind >= size_ || ind < 0) {
            throw std::runtime_error("Incorrect ind");
        }
        return data_[ind];
    }

    T& Front() {
        if (size_ == 0) {
            throw std::runtime_error("Incorrect ind");
        }
        return data_[0];
    }

    T& Back() {
        if (size_ == 0) {
            throw std::runtime_error("Incorrect ind");
        }
        return data_[size_ - 1];
    }

private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t place_ = 0;
};

int main() {
    {
        Vector<int> cur;
        cur.Push_back(1);
        cur.Push_back(2);
        cur.Push_back(3);
        assert(cur.Size() == 3);
        assert(cur.Front() == 1);
        assert(cur[0] == 1);
        assert(cur[1] == 2);
        assert(cur[2] == 3);
        assert(cur.Back() == 3);
        std::cout << "test 1 OK" << std::endl;
    }
    {
        Vector<int> cur;
        cur.Push_back(1);
        cur.Push_back(2);
        cur.Pop_back();
        assert(cur.Size() == 1);
        assert(cur[0] == 1);
        std::cout << "test 2 OK" << std::endl;
    }
    {
        Vector<int> cur;
        cur.Push_back(1);
        cur.Push_back(2);
        cur.Push_back(3);
        assert(cur.At(0) == 1);
        assert(cur.At(1) == 2);
        assert(cur.At(2) == 3);
        assert(cur.Size() == 3);
        assert(!cur.Empty());
        cur.Clear();
        assert(cur.Size() == 0);
        assert(cur.Empty());
        std::cout << "test 3 OK" << std::endl;
    }
    {
        Vector<char> a;
        for (int i = 0; i < 27; ++i) {
            a.Push_back('a' + i);
        }
        assert(a.Size() == 27);
        assert(a.Back() == a.Front() + 26);
        std::cout << "test 4 OK" << std::endl;
    }
}