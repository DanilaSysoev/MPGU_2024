class Movable {
public:
    Movable(int size);
    Movable(const Movable& other);
    Movable(Movable&& other);
    
    Movable& operator=(const Movable& other);
    Movable& operator=(Movable&& other);

    int getSize() const { return size; }
    int& operator[](int index) { return data[index]; }
    int operator[](int index) const { return data[index]; }

    ~Movable();

private:
    int size;
    int* data;
};