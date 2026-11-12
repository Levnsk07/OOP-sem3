#include "circular_buffer.h"

#include <exception>


//В этой задаче для простоты не требуется делать контейнер шаблонным,
//но это вполне допускается по желанию студента.
typedef char value_type;

class CircularBuffer {
    value_type *buffer;
    int capacity;
    int occupancy = 0;
    /*... реализация ... */
public:
    CircularBuffer();

    ~CircularBuffer();

    CircularBuffer(const CircularBuffer &cb) {
        buffer = cb.buffer;
    }

    //Конструирует буфер заданной ёмкости.
    explicit CircularBuffer(int capacity) {
        buffer = new value_type[capacity];
        this->capacity = capacity;
        for (value_type *val: buffer) {
            val = NULL;
        }
    }

    //Конструирует буфер заданной ёмкости, целиком заполняет его элементом elem.
    CircularBuffer(int capacity, const value_type &elem) {
        buffer = new value_type[capacity];
        this->capacity = capacity;
        for (int i = 0; i < capacity; i++) {
            buffer[i] = elem;
        }
    }

    //Доступ по индексу. Не проверяют правильность индекса.
    value_type &operator[](int i) {
        return buffer[i];
    }

    const value_type &operator[](int i) const {
        return buffer[i];
    }

    //Доступ по индексу. Методы бросают исключение в случае неверного индекса.
    value_type &at(int i) {
        value_type temp;
        try {
            temp = buffer[i];
        } catch (std::exception e) {
            throw new std::exception();
        }
        return temp;
    }

    const value_type &at(int i) const {
        if (i < occupancy && i > 0) {
            return buffer[i];
        }
        throw new std::exception();
    }

    //Ссылка на первый элемент.
    value_type &front() {
        return buffer[0];
    }

    //Ссылка на последний элемент.
    value_type &back() {
        return buffer[occupancy - 1];
    }

    const value_type &front() const {
        return buffer[0];
    }

    const value_type &back() const {
        return buffer[occupancy - 1];
    }


    //Линеаризация - сдвинуть кольцевой буфер так, что его первый элемент
    //переместится в начало аллоцированной памяти. Возвращает указатель
    //на первый элемент.
    value_type *linearize() {
        for (int i = 1; i < capacity; i++) {
            value_type temp = buffer[i];
            buffer[i] = buffer[i - 1];
        }
        return buffer;
    }

    //Проверяет, является ли буфер линеаризованным.
    bool is_linearized() const {
        bool linearized = true;
        for (value_type c: buffer) {
            if (c == NULL) linearized = false;
            if (!linearized && c != NULL) { return false; }
        }

        return true;
    }

    //Сдвигает буфер так, что по нулевому индексу окажется элемент
    //с индексом new_begin.
    void rotate(int new_begin);

    //Количество элементов, хранящихся в буфере.
    int size() const;

    bool empty() const;

    //true, если size() == capacity().
    bool full() const;

    //Количество свободных ячеек в буфере.
    int reserve() const;

    //ёмкость буфера
    int capacity() const;

    void set_capacity(int new_capacity);

    //Изменяет размер буфера.
    //В случае расширения, новые элементы заполняются элементом item.
    void resize(int new_size, const value_type &item = value_type());

    //Оператор присваивания.
    CircularBuffer &operator=(const CircularBuffer &cb);

    //Обменивает содержимое буфера с буфером cb.
    void swap(CircularBuffer &cb);

    //Добавляет элемент в конец буфера.
    //Если текущий размер буфера равен его ёмкости, то переписывается
    //первый элемент буфера (т.е., буфер закольцован).
    void push_back(const value_type &item = value_type());

    //Добавляет новый элемент перед первым элементом буфера.
    //Аналогично push_back, может переписать последний элемент буфера.
    void push_front(const value_type &item = value_type());

    //удаляет последний элемент буфера.
    void pop_back();

    //удаляет первый элемент буфера.
    void pop_front();

    //Вставляет элемент item по индексу pos. Ёмкость буфера остается неизменной.
    void insert(int pos, const value_type &item = value_type());

    //Удаляет элементы из буфера в интервале [first, last).
    void erase(int first, int last);

    //Очищает буфер.
    void clear();
};

bool operator==(const CircularBuffer &a, const CircularBuffer &b);

bool operator!=(const CircularBuffer &a, const CircularBuffer &b);
