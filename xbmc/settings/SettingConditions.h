/*
 *  Copyright (C) 2014-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include <set>
#include <string>

#include "settings/lib/SettingConditions.h"

class CProfile;
class CProfilesManager;

class CSettingConditions
{
public:
  static void Initialize(const CProfilesManager &profileManager);
  static void Deinitialize();

  static const CProfile& GetCurrentProfile();

  static const std::set<std::string>& GetSimpleConditions() { return m_simpleConditions; }
  static const std::map<std::string, SettingConditionCheck>& GetComplexConditions() { return m_complexConditions; }

  static bool Check(const std::string &condition, const std::string &value = "", std::shared_ptr<const CSetting> setting = NULL);

private:
  // Initialization parameters
  static const CProfilesManager *m_profileManager;

  static std::set<std::string> m_simpleConditions;
  static std::map<std::string, SettingConditionCheck> m_complexConditions;
};
