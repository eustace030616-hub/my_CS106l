class StanfordID {
    private:
        using string = std::string;
        string name;
        string sunet;
        int IDnumber;

    public:
    StanfordID(string name, string sunet, int IDnumber);    //constructor
    string getname();
    string getsunnet();
    int getIDnumber();
}