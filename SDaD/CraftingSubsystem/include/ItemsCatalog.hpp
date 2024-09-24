#include <cstdint>
#include <optional>

namespace Crafting
{
    class Item;

    class ItemsCatalog
    {
    public:
        uint32_t GetSize() const { return _items.size(); }
        void AddItem(const Item& item);
        const Item& GetItem(const std::string& name) const;

        static ItemsCatalog& Get();
        static void Create();
        static void Clear();

    private:
        std::vector<Item> _items;
        
        std::optional<const Crafting::Item>
        GetByName(const std::string& name) const;
        
        static ItemsCatalog _instance;
        static bool _created;
    };
}