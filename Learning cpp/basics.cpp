/*  
/***********************          OPERADORES          ***********************/       
/*
x+=y // x = x+y
++x // increment: x = x+1
x−=y // x = x-y
−−x // decrement: x = x-1
x∗=y // scaling: x = x*y
x/=y // scaling: x = x/y
x%=y // x = x%y
x+=y // x = x+y
++x // increment: x = x+1
x−=y // x = x-y
−−x // decrement: x = x-1
x∗=y // scaling: x = x*y
x/=y // scaling: x = x/y
x%=y // x = x%y
*/

/***********************          CLASSES          ***********************/       

/*Having the data specified separately from the operations on it has advantages, such as the ability to
use the data in arbitrary ways. However, a tighter connection between the representation and the
operations is needed for a user-defined type to have all the properties expected of a ‘‘real type.’’ In
particular, we often want to keep the representation inaccessible to users, so as to ease use, guarantee consistent use of the data, and allow us to later improve the representation. To do that we have
to distinguish between the interface to a type (to be used by all) and its implementation (which has
access to the otherwise inaccessible data). The language mechanism for that is called a class. A
class is defined to have a set of members, which can be data, function, or type members. The interface is defined by the public members of a class, and private members are accessible only through
that interface. */
/*
EXAMPLE:
    class Vector {
        public:
            Vector(int s) :elem{new double[s]}, sz{s} { } // constr uct a Vector
            double& operator[](int i) { return elem[i]; } // element access: subscripting
            int size() { return sz; }
        private:
            double∗ elem; // pointer to the elements
            int sz; // the number of elements
    };
*/

/***********************          TIPOS NUMERATIVOS          ***********************/       

/*
In addition to classes, C++ supports a simple form of user-defined type for which we can enumerate the values:

    enum class Color { red, blue , green };
    enum class Traffic_light { green, yellow, red };

    Color col = Color::red;
    Traffic_light light = Traffic_light::red;

Note that enumerators (e.g., red) are in the scope of their enum class, so that they can be used
repeatedly in different enum classes without confusion. For example, Color::red is Color’s red
which is different from Traffic_light::red.

The class after the enum specifies that an enumeration is strongly typed and that its enumerators
are scoped. Being separate types, enum classes help prevent accidental misuses of constants. In
particular, we cannot mix Traffic_light and Color values:

    Color x = red;                  // error : which red?
    Color y = Traffic_light::red;   // error : that red is not a Color
    Color z = Color::red;           // OK

Similarly, we cannot implicitly mix Color and integer values:

    int i = Color::red; // error : Color ::red is not an int
    Color c = 2; // error : 2 is not a Color

By default, an enum class has only assignment, initialization, and comparisons (e.g., == and <;)defined.
However, an enumeration is a user-defined type so we can define operators for it:

    Traffic_light& operator++(Traffic_light& t)  //prefix increment: ++
    {
        switch (t) 
        {
            case Traffic_light::green: return t=Traffic_light::yellow;
            case Traffic_light::yellow: return t=Traffic_light::red;
            case Traffic_light::red: return t=Traffic_light::green;
        }
    }
    Traffic_light next = ++light;               // next becomes Traffic_light::green

*/