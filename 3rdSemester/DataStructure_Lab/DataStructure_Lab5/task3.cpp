#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000;

class char_stack
{
    char arr[MAX];
    int top;

public:
    char_stack() : top(-1) {}

    bool is_empty()
    {
        return top == -1;
    }

    bool is_full()
    {
        return top == MAX - 1;
    }

    void push(char c)
    {
        if (is_full())
        {
            cout << "stack is full.\n";
            return;
        }
        arr[++top] = c;
    }

    char pop()
    {
        if (is_empty())
        {
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (is_empty())
        {
            return '\0';
        }
        return arr[top];
    }
};

class int_stack
{
    int arr[MAX];
    int top;

public:
    int_stack() : top(-1) {}

    bool is_empty()
    {
        return top == -1;
    }

    bool is_full()
    {
        return top == MAX - 1;
    }

    void push(int num)
    {
        if (is_full())
        {
            cout << "stack is full.\n";
            return;
        }
        arr[++top] = num;
    }

    int pop()
    {
        if (is_empty())
        {
            return 0;
        }
        return arr[top--];
    }

    int get_size()
    {
        return top + 1;
    }
};

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int get_precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '^')
    {
        return 3;
    }
    return 0;
}

int calculate_power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result = result * base;
    }
    return result;
}

string infix_to_postfix(string infix)
{
    char_stack op_stack;
    string postfix = "";
    bool last_was_op = true;
    int open_parens = 0;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (c == ' ')
        {
            continue;
        }

        if (is_digit(c))
        {
            while (i < infix.length() && is_digit(infix[i]))
            {
                postfix = postfix + infix[i];
                i++;
            }
            postfix = postfix + " ";
            i--; 
            last_was_op = false;
        }
        else if (c == '(')
        {
            op_stack.push(c);
            open_parens++;
            last_was_op = true;
        }
        else if (c == ')')
        {
            if (open_parens == 0 || last_was_op)
            {
                return "ERROR";
            }
            while (!op_stack.is_empty() && op_stack.peek() != '(')
            {
                postfix = postfix + op_stack.pop() + " ";
            }
            if (!op_stack.is_empty())
            {
                op_stack.pop(); 
            }
            open_parens--;
            last_was_op = false;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (last_was_op)
            {
                return "ERROR";
            }
            while (!op_stack.is_empty() && op_stack.peek() != '(')
            {
                int prec_c = get_precedence(c);
                int prec_stack = get_precedence(op_stack.peek());
                
                if (c == '^' && prec_c < prec_stack)
                {
                    postfix = postfix + op_stack.pop() + " ";
                }
                else if (c != '^' && prec_c <= prec_stack)
                {
                    postfix = postfix + op_stack.pop() + " ";
                }
                else
                {
                    break;
                }
            }
            op_stack.push(c);
            last_was_op = true;
        }
        else
        {
            return "ERROR"; 
        }
    }

    if (open_parens != 0 || last_was_op)
    {
        return "ERROR";
    }

    while (!op_stack.is_empty())
    {
        postfix = postfix + op_stack.pop() + " ";
    }

    return postfix;
}

int evaluate_postfix(string postfix, bool& has_error)
{
    int_stack val_stack;
    has_error = false;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (c == ' ')
        {
            continue;
        }

        if (is_digit(c))
        {
            int num = 0;
            while (i < postfix.length() && is_digit(postfix[i]))
            {
                num = (num * 10) + (postfix[i] - '0');
                i++;
            }
            val_stack.push(num);
            i--; 
        }
        else
        {
            if (val_stack.get_size() < 2)
            {
                has_error = true;
                return 0;
            }
            
            int right_val = val_stack.pop();
            int left_val = val_stack.pop();
            int ans = 0;

            if (c == '+')
            {
                ans = left_val + right_val;
            }
            else if (c == '-')
            {
                ans = left_val - right_val;
            }
            else if (c == '*')
            {
                ans = left_val * right_val;
            }
            else if (c == '/')
            {
                if (right_val == 0)
                {
                    has_error = true;
                    return 0;
                }
                ans = left_val / right_val;
            }
            else if (c == '^')
            {
                ans = calculate_power(left_val, right_val);
            }

            val_stack.push(ans);
        }
    }

    if (val_stack.get_size() != 1)
    {
        has_error = true;
        return 0;
    }

    return val_stack.pop();
}

void process_expression(string expr)
{
    cout << "input: " << expr << "\n";
    string post = infix_to_postfix(expr);
    
    if (post == "ERROR")
    {
        cout << "error: malformed expression detected.\n\n";
        return;
    }
    
    bool eval_err = false;
    int final_ans = evaluate_postfix(post, eval_err);
    
    if (eval_err)
    {
        cout << "error: could not evaluate expression.\n\n";
    }
    else
    {
        cout << "result: " << final_ans << "\n\n";
    }
}

int main()
{
    process_expression("12 + 3 * (4 - 1)");
    process_expression("(2 + 3) ^ 2");
    process_expression("100 / 5 / 2");
    process_expression("5 + )");
    
    return 0;
}