#pragma once

#include <memory>

#include "Event/Event.hpp"
#include "GL/Camera.hpp"
#include "Input/InputManager.hpp"
#include "Input/InputHandler.hpp"
#include "Input/KeyEvent.hpp"

namespace OGLDemo
{
    class CameraController :
            public OGL::InputHandler<OGL::KeyEvent>,
            public OGL::InputHandler<OGL::MouseMoveEvent>,
            public OGL::InputHandler<OGL::MouseScrollEvent>
    {
    public:
        explicit CameraController(std::shared_ptr<OGL::Camera> camera);

        static std::shared_ptr<CameraController> Create(const std::shared_ptr<OGL::Camera>& camera);

        void Handle(OGL::KeyEvent) override;
        void Handle(OGL::MouseMoveEvent) override;
        void Handle(OGL::MouseScrollEvent) override;

        void Update(double deltaTime);

    private:
        std::shared_ptr<OGL::Camera> m_camera;

        bool m_moveForward = false;
        bool m_moveBackward = false;
        bool m_strafeLeft = false;
        bool m_strafeRight = false;
        bool m_ascend = false;
        bool m_descend = false;

        bool m_receivedFirstMouseMoveEvent = true;
        float m_rotateX, m_rotateY, m_lastCursorX, m_lastCursorY;
    };
}
