#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

namespace math{
    class Equation{
    protected:
        double x1, x2;
    public:
        Equation () : x1(0), x2(0){};
        Equation(const double& x) : x1(x), x2(0){};
        Equation(const double& x, const double& x0) : x1(x), x2(x0){};
        virtual ~Equation() {};
    };

    class Line : public Equation{
    private:
        double k, l, y;
    public:
        Line() : Equation(0), k(0), l(0){};
        Line(const double& k1, const double& l1, const double& y1)  : Equation(0, 0), y(y1), k(k1), l(l1){};
        void searchX(){
            x1 = (y-l)/k;
            cout << "x = " << x1 << endl;
        }
    };

    class Square : public Equation{
    private:
        double a, b, c, y, d;
    public:
        Square() : Equation(0), a(0), b(0), c(0){};
        Square(const double& a1, const double& b1, const double& c1, const double& y1) : Equation(0, 0), a(a1), b(b1), c(c1), y(y1){};
        void searchX(){
            d = b*b + 4*a*c;
            x1 = (-b+sqrt(d))/(2*a);
            x2 = (-b-sqrt(d))/(2*a);
            
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    };
    class Shape{
    public:
        virtual void Show(){}
        virtual void Save(){}
        virtual void Load(){}
        virtual ~Shape() {};
    };

    class SSquare : public Shape{
    private:
        int x, y, a;
    public:
        SSquare() : x(0), y(0), a(0){};
        SSquare(const int& x1, const int& y1, const int& a1) : x(x1), y(y1), a(a1){};
        
        void Show() override{
            cout << "x = " << x << ", y = " << y << ", side = " << a << endl;
        }
        void Save() override{
            ofstream fout("square.txt");
            fout << "x = " << x << ", y = " << y << ", side = " << a;
            fout.close();
        }
        void Load() override{
            ifstream fin("square.txt");
            if (fin.is_open()) {
                char delimiter;
                string dummy;

                fin >> dummy >> delimiter >> x;
                
                fin >> delimiter >> dummy >> delimiter >> y;
                    
                fin >> delimiter >> dummy >> delimiter >> a;
                    
                fin.close();
                cout << "All datas were loaded from 'square.txt'." << endl;

            } else {
                cout << "Sth was wrong!" << endl;
            }
        }
    };

    class Rectangle : public Shape{
    private:
        int x, y, a, b;
    public:
        Rectangle() : x(0), y(0), a(0), b(0){};
        Rectangle(const int& x1, const int& y1, const int& a1, const int& b1) : x(x1), y(y1), a(a1), b(b1){};
        
        void Show() override{
            cout << "x = " << x << ", y = " << y << ", the first side = " << a << ", the second side = "<< b << endl;
        }
        void Save() override{
            ofstream fout("rectangle.txt");
            fout << "x = " << x << ", y = " << y << ", the first side = " << a << ", the second side = "<< b;
            fout.close();
        }
        void Load() override{
            ifstream fin("rectangle.txt");
            if (fin.is_open()) {
                char delimiter;
                string dummy;

                fin >> dummy >> delimiter >> x;
                
                fin >> delimiter >> dummy >> delimiter >> y;
                    
                fin >> delimiter >> dummy >> delimiter >> a;
                
                fin >> delimiter >> dummy >> delimiter >> a;
                    
                fin.close();
                cout << "All datas were loaded from 'rectangle.txt'." << endl;

            } else {
                cout << "Sth was wrong!" << endl;
            }
        }
    };

    class Circle : public Shape{
    private:
        int x, y, r;
    public:
        Circle() : x(0), y(0), r(0){};
        Circle(const int& x1, const int& y1, const int& r1) : x(x1), y(y1), r(r1){};
        
        void Show() override{
            cout << "x = " << x << ", y = " << y << ", radious = " << r << endl;
        }
        void Save() override{
            ofstream fout("circle.txt");
            fout << "x = " << x << ", y = " << y << ", radious = " << r;
            fout.close();
        }
        void Load() override{
            ifstream fin("circle.txt");
            if (fin.is_open()) {
                char delimiter;
                string dummy;

                fin >> dummy >> delimiter >> x;
                
                fin >> delimiter >> dummy >> delimiter >> y;
                    
                fin >> delimiter >> dummy >> delimiter >> r;
                    
                fin.close();
                cout << "All datas were loaded from 'circle.txt'." << endl;

            } else {
                cout << "Sth was wrong!" << endl;
            }
        }
    };

    class Ellipse : public Shape{
    private:
        int x, y, a, b;
    public:
        Ellipse() : x(0), y(0), a(0), b(0){};
        Ellipse(const int& x1, const int& y1, const int& a1, const int& b1) : x(x1), y(y1), a(a1), b(b1){};
        
        void Show() override{
            cout << "x = " << x << ", y = " << y << ", axis1 = " << a << ", axis2 = "<< b << endl;
        }
        void Save() override{
            ofstream fout("circle.txt");
            fout << "x = " << x << ", y = " << y << ", axis1 = " << a << ", axis2 = "<< b;
            fout.close();
        }
        void Load() override{
            ifstream fin("circle.txt");
            if (fin.is_open()) {
                char delimiter;
                string dummy;

                fin >> dummy >> delimiter >> x;
                
                fin >> delimiter >> dummy >> delimiter >> y;
                    
                fin >> delimiter >> dummy >> delimiter >> a;
                
                fin >> delimiter >> dummy >> delimiter >> a;
                    
                fin.close();
                cout << "All datas were loaded from 'circle.txt'." << endl;

            } else {
                cout << "Sth was wrong!" << endl;
            }
        }
    };
}

namespace mp{
    struct Name{
        string name, surname;
    };
    struct Address{
        string country, region, city, street;
        int building, appartmant;
    };

    struct Visa{
        int number, numOfEntries;
        string type, issuedIn, country;
        tm startDay{}, endDay{};
        
    };

    class Passport{
    private:
        int seriesM, dateOfBarthday, dateOfIssueM, dateOfExpiryM, taxNumber;
        Name name;
        Address address;
    public:
        Passport(const int& s, const int& d1, const int& d2, const int& d3, const int& t, const Name& n, const Address& a):
        seriesM(s), dateOfBarthday(d1), dateOfIssueM(d2), dateOfExpiryM(d3), taxNumber(t), name(n), address(a) {};
        
        void print() const {
                cout << "=== Passport Information ===\n";
                cout << "Series: " << seriesM << endl;
                cout << "Name: " << name.name << " " << name.surname << endl;
                cout << "Date of birth: " << dateOfBarthday << endl;
                cout << "Date of issue: " << dateOfIssueM << endl;
                cout << "Date of expiry: " << dateOfExpiryM << endl;
                cout << "Tax number: " << taxNumber << endl;
                cout << "Address: " << address.country << ", " << address.region << ", "
                     << address.city << ", " << address.street << " "
                     << address.building << "/" << address.appartmant << endl;
            }
    };

    class ForeignPassport : public Passport{
    private:
        int seriesA, dateOfIssueA, dateOfExpiryA;
        vector<Visa> visa;
    public:
        ForeignPassport(const int& sA, const int& d1A, const int& d2A,
                            const int& sM, const int& d1M, const int& d2M,
                            const int& d3M, const int& t,
                            const Name& n, const Address& a, const vector<Visa>& v)
                : Passport(sM, d1M, d2M, d3M, t, n, a),
                seriesA(sA), dateOfIssueA(d1A), dateOfExpiryA(d2A), visa(v) {};
        
        void print() const {
                cout << "\n=== Foreign Passport Information ===\n";
                Passport::print();
                cout << "Foreign passport series: " << seriesA << endl;
                cout << "Foreign passport issue date: " << dateOfIssueA << endl;
                cout << "Foreign passport expiry date: " << dateOfExpiryA << endl;

                for (size_t i = 0; i < visa.size(); i++) {
                    cout << "\n--- Visa #" << (i + 1) << " ---\n";
                    cout << "Number: " << visa[i].number << endl;
                    cout << "Available entries: " << visa[i].numOfEntries << endl;
                    cout << "Type: " << visa[i].type << endl;
                    cout << "Issued in: " << visa[i].issuedIn << endl;
                    cout << "Country: " << visa[i].country << endl;

                    cout << "Valid from: " << visa[i].startDay.tm_mday << "."
                         << visa[i].startDay.tm_mon + 1 << "."
                         << visa[i].startDay.tm_year + 1900 << endl;

                    cout << "Valid until: " << visa[i].endDay.tm_mday << "."
                         << visa[i].endDay.tm_mon + 1 << "."
                         << visa[i].endDay.tm_year + 1900 << endl;
                }
            }
    };
}

int main() {
    math::Square sq1(1.0, 5.0, 6.0, 0.0);
    cout << "Пошук коренів x^2 + 5x + 6 = 0:" << endl;
    sq1.searchX(); // x1 = -2, x2 = -3
    
    cout << "\n------------------\n";
    
    // Приклад використання Line
    // Рівняння: y = 2x + 3. Шукаємо x. 4 = 2*x + 3 = 11
    math::Line ln1(2.0, 3.0, 4.0);
    cout << "Пошук X для y = 2x + 3 при y=4:" << endl;
    ln1.searchX();
    
    math::SSquare sq(1, 1, 10);
    math::Rectangle rect(10, 20, 5, 8);
    math::Circle circ(50, 50, 15);
    math::Ellipse el(100, 100, 30, 20);
    
    cout << "--- 1. Початковий стан та Збереження ---" << endl;
    
    sq.Show();
    rect.Show();
    circ.Show();
    el.Show();
    
    // Зберігаємо всі фігури
    sq.Save();
    rect.Save();
    circ.Save();
    el.Save();

    cout << "\n--- 2. Перезавантаження (ініціалізація нових об'єктів нулями) ---" << endl;
    
    // 2. Створюємо нові об'єкти з нульовими параметрами
    math::SSquare new_sq;
    math::Rectangle new_rect;
    math::Circle new_circ;
    math::Ellipse new_el;
    
    // Перевіряємо, що вони нульові
    new_sq.Show();
    new_rect.Show();
    new_circ.Show();
    new_el.Show();

    cout << "\n--- 3. Завантаження даних ---" << endl;
    
    // 3. Завантажуємо збережені дані
    new_sq.Load();
    new_rect.Load();
    new_circ.Load();
    new_el.Load();
    
    cout << "\n--- 4. Перевірка завантажених даних ---" << endl;
    
    // 4. Перевіряємо, чи збігаються дані
    new_sq.Show();   // Очікуємо: 1, 1, 10
    new_rect.Show(); // Очікуємо: 10, 20, 5, 8
    new_circ.Show(); // Очікуємо: 50, 50, 15
    new_el.Show();   // Очікуємо: 100, 100, 30, 20
    
    cout << "\n--- 5. Поліморфізм (з Shape*) ---" << endl;
    
    // Демонстрація поліморфізму
    vector<math::Shape*> shapes;
    shapes.push_back(new math::Shape()); // Порожній об'єкт Shape (для прикладу)
    shapes.push_back(&new_sq);
    shapes.push_back(&new_rect);

    for (math::Shape* s : shapes) {
        s->Show(); // Викликається правильний Show() для кожного типу
    }
    
    // Прибирання: видалення об'єктів, створених через покажчик
    for (math::Shape* s : shapes) {
        delete s;
    }
    
    /*
     mp::Name n = {"Ivan", "Petrov"};
     mp::Address a = {"Ukraine", "Kyiv region", "Kyiv", "Khreshchatyk", 10, 5};

     tm start1 = {0, 0, 0, 12, 5, 125};
     tm end1 = {0, 0, 0, 12, 5, 126};

     mp::Visa v1 = {12345, 2, "Tourist", "Kyiv", "France", start1, end1};
     vector<mp::Visa> visas = {v1};

     mp::ForeignPassport fp(9999, 2022, 2032, 1111, 1999, 2015, 2025, 987654, n, a, visas);
     fp.print();
     */
}
