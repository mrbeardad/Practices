#include <string>
/*! \class Base
 *  \brief Tst
 *
 *  Detailed description
 */
class Base
{
public:
    virtual ~Base() =default;
    virtual std::string& highlight(std::string& text) =0;
    virtual std::string highlight(std::string&& text)
    {
        return highlight(text);
    }
};

/*! \class Derv
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Derv : public Base
{
public:
    std::string& highlight(std::string& text) override
    {
        return text.assign("fuck");
    }
};
