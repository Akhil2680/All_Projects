#include <iostream>
    #include <vector>
    #include <limits>
    
    using namespace std;
    
    class Stack {
    private:
        vector<int> stack; 
        int maxSize;       
    
    public:
       
        Stack(int size) : maxSize(size) {}
    
     
        void push(int value) {
            if (stack.size() == maxSize) {
                cout << "Stack Overflow! Cannot push " << value << "." << endl;
            } else {
                stack.push_back(value);
                cout << value << " pushed onto the stack." << endl;
            }
        }
    
        
        void pop() {
            if (stack.empty()) {
                cout << "Stack Underflow! No elements to pop." << endl;
            } else {
                int poppedValue = stack.back();
                stack.pop_back();
                cout << "Popped: " << poppedValue << endl;
            }
        }
    
       
        void peek() {
            if (stack.empty()) {
                cout << "Stack is empty. Nothing to peek." << endl;
            } else {
                cout << "Top of the stack: " << stack.back() << endl;
            }
        }
    
       
        void display() {
            if (stack.empty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack elements (from top to bottom): ";
                for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }
    
        
        void clear() {
            stack.clear();
            cout << "Stack cleared." << endl;
        }
    };
    
    int main() {
        int choice, value, maxSize;
    
        cout << "Enter the maximum size of the stack: ";
        cin >> maxSize;
    
        Stack myStack(maxSize);
    
        do {
            cout << "\n--- Stack Simulator ---" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Peek" << endl;
            cout << "4. Display" << endl;
            cout << "5. Clear Stack" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
    
           
            while (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid input. Please enter a number: ";
                cin >> choice;
            }
    
            switch (choice) {
                case 1:
                    cout << "Enter value to push: ";
                    cin >> value;
                    myStack.push(value);
                    break;
                case 2:
                    myStack.pop();
                    break;
                case 3:
                    myStack.peek();
                    break;
                case 4:
                    myStack.display();
                    break;
                case 5:
                    myStack.clear();
                    break;
                case 6:
                    cout << "Exiting program. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 6);
    
        return 0;
    }
    