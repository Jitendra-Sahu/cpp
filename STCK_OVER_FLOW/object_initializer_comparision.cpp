#include <string>
#include <map>

class FileInfo
{
public:
    FileInfo(const std::string &name) : mName(name) { }

    bool operator == (const FileInfo& other) const
    {
        return mName == other.mName;
    }

private:
    std::string mName;
};

int main(int argc, char *argv[])
{
    FileInfo f1("f1") ;
    FileInfo f2("f2") ;

    if (f1 == f2) {} // OK

    if (f1 == ("f2")) {} // C2059 syntax error: ')'

    if ((f1 = "f1") == f2) { } // OK

    if (f1 == FileInfo("f2")) {} // OK

    return 0;
}
