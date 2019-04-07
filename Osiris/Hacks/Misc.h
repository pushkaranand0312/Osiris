#pragma once

#include "../Memory.h"
#include "../SDK/UserCmd.h"

namespace Misc {
    void inverseRagdollGravity() noexcept;
    void autoPistol(UserCmd*) noexcept;
    void revealRanks() noexcept;
    void animateClanTag(const char* = nullptr) noexcept;
    void spectatorList() noexcept;
    void sniperCrosshair() noexcept;
    void recoilCrosshair() noexcept;

    constexpr void autoStrafe(UserCmd* cmd) noexcept
    {
        if (config.misc.autoStrafe
            && !(interfaces.entityList->getEntity(interfaces.engine->getLocalPlayer())->getProperty<int>("m_fFlags") & 1)) {
            if (cmd->mousedx < 0)
                cmd->sidemove = -450.0f;
            else if (cmd->mousedx > 0)
                cmd->sidemove = 450.0f;
        }
    }

    constexpr void bunnyHop(UserCmd* cmd) noexcept
    {
        if (config.misc.bunnyHop && cmd->buttons & UserCmd::IN_JUMP
            && !(interfaces.entityList->getEntity(interfaces.engine->getLocalPlayer())->getProperty<int>("m_fFlags") & 1)) {
            cmd->buttons &= ~UserCmd::IN_JUMP;
        }
    }

    constexpr void removeCrouchCooldown(UserCmd* cmd) noexcept
    {
        if (config.misc.fastDuck)
            cmd->buttons |= UserCmd::IN_BULLRUSH;
    }

    constexpr void setClanTag(const char* clanTag) noexcept
    {
        memory.setClanTag(clanTag, clanTag);
    }

    constexpr void watermark() noexcept
    {
        if (config.misc.watermark) {
            interfaces.surface->setTextColor(51, 153, 255, 255);
            interfaces.surface->setTextPosition(0, 0);
            interfaces.surface->printText(L"Osiris");
        }
    }
}
