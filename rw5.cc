#include <thread>
#include <iostream>

int shared = 0;

void writer(int id) {
    shared = id;
}

void reader(int id) {
    int val = shared;
    std::cout << "Thread " << id << " read: " << val << std::endl;
}

int main() {
    std::thread t1(writer, 1);
    std::thread t2(reader, 2);
    std::thread t3(writer, 3);
    std::thread t4(reader, 4);
    std::thread t5(writer, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
