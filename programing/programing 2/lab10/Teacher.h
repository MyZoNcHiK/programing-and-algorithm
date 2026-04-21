#ifndef lab10
#define lab10
class Teacher{
    private:
    string surname_name;
    string cathedra;
    int exp; 
    public:
        Teacher(
            string sn,
            string cath, 
            int exp, 
            string disc);
        string get_surname_name() const;
        string get_cathedra() const;
        int get_exp() const;
};
#endif