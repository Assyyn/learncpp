// to avoid naming collisions between enums, we can use namespaces
// using namespaces also prevents you from polluting the global namespace
namespace item
{
enum ItemType
{
    weapon,
    potion,
    food,
    nothing,
};
}

namespace clothing
{
enum Clothes
{
    armor,
    regular,
    fancy,
    nothing, // no namespace collisions with ItemType::nothing
};
}

// no naming collisions in the global namespace
struct Player // program-defined type for a 'player'
{
    item::ItemType holding{item::nothing}; // defaults of a new Player
    clothing::Clothes wearing{clothing::nothing};
};
