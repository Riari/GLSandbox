#pragma once

#include "Entity/Entity.hpp"
#include "Event/Event.hpp"

namespace Iris
{
    class AddComponentEvent : public Event
    {
    public:
        AddComponentEvent(EntityId entityId, ComponentType componentType);

        [[nodiscard]] EntityId GetEntityId() const;
        [[nodiscard]] ComponentType GetComponentType() const;

    private:
        EntityId m_entityId;
        ComponentType m_componentType;
    };
}