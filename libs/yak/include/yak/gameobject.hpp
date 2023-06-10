#pragma once
#include <yak/components/component.hpp>

namespace Yak
{
    class GameObject
    {
    public:
        GameObject(int priority = 1000);
        ~GameObject();

        void Init();
        void Update(float dt);
        void Render();

        void AddComponent(Component *cpt);
        void
    }
}