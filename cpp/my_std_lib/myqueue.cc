#include "Stack.cc"
#include <memory>


template <class T>
class MyQueue
{
private:
    // std::unique_ptr<Stack<T>> main_stack;
    // std::unique_ptr<Stack<T>> temp_stack;
    Stack<T> _main_stack;
    Stack<T> _tmp_stack;
    size_t _size{0};
public:
    size_t size() 
    {
        return _size;
    }

    void push(T data) 
    {
        _main_stack.push(data);
        _size++;
    }

    T pop() 
    {
        if (_size == 0)
        {
            return -1;
        } 

        while (_main_stack.size() > 0) 
        {
            _tmp_stack.push(_main_stack.pop());
        }

        T result = _tmp_stack.pop(); // This is the node we're returning    
        while (_tmp_stack.size() > 0) 
        {
            _main_stack.push(_tmp_stack.pop());
        }
        _size--;
        
        return result;
    }
};

int main()
{
    MyQueue<int> int_queue;
    std::cout << std::endl;
    std::cout << "pushing: ";
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << i << " ";
        int_queue.push(i);

   } std::cout << std::endl;

    std::cout << "size: " << int_queue.size() << std::endl;
     
    std::cout << "poppin': ";
    for (size_t i = 0; i < 39; i++)
    {
        std::cout << int_queue.pop() << " ";
    } std::cout << std::endl;

    std::cout << "size: " << int_queue.size() << std::endl;


    return 0;
}