#include <string>

namespace Crafting
{
    class Item
    {
    public:
        std::string GetName() const { return _name; }

        static Item Create(const std::string& name);


    private:
        Item(const std::string& name);
        std::string _name;
    };
}