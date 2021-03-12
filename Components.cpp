#include <map>
#include <string>
#include <typeinfo>
#include <iostream>
#include <cassert>

class Component {

};

class Collider : public Component {
public:
    int geometry;
};

class Renderer : public Component {
public:
    int sprite;
};

class GameObject
{
    std::map<std::string, Component*> components;

public:
    template <typename T>
    T* GetComponent()
    {
        assert(components[typeid(T).name()] != 0);
        T* comp = new T;
        comp = static_cast<T*>(components[typeid(T).name()]);
        return comp;
    };

    template <typename T>
    void AddComponent()
    {
        components[typeid(T).name()] = new T;
    };

    template <typename T>
    void RemoveComponent()
    {
        components.erase(typeid(T).name());
    };
};

void graphics(GameObject obj)
{
    Renderer* r = obj.GetComponent<Renderer>();
}

int main()
{
    GameObject obj;

    obj.AddComponent<Renderer>();
    obj.AddComponent<Collider>();

    obj.RemoveComponent<Renderer>();

    //std::cout << obj.GetComponent<Renderer>()->sprite;
    std::cout << obj.GetComponent<Collider>()->geometry;

    //graphics(obj);
}