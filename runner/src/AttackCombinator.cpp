/*
* Author : see AUTHORS
* Licence: MIT, see LICENSE
*/

#include "AttackCombinator.hpp"

AttackCombinator::AttackCombinator(const ConfigTask& config, Directory& directory) : AttackCrackingBase(config, directory) {
  
}

void AttackCombinator::addSpecificArguments() {

  AttackCrackingBase::addSpecificArguments();

  if (attack_submode_ == "0") {

    // Do nothing just at the end add dictionaries

  } else if (attack_submode_ == "1") {

    findAndAddRequired("rule_left", "--rule-left");

  } else if (attack_submode_ == "2") {

    findAndAddRequired("rule_right", "--rule-right");

  } else if (attack_submode_ == "3") {

    findAndAddRequired("rule_left", "--rule-left");
    findAndAddRequired("rule_right", "--rule-right");

  } else {
    RunnerUtils::runtimeException("Unsupported attack_submode = " + attack_submode_ + " attack_mode = " + attack_mode_ + " has no such attack_submode");
  }

  addRequiredFile("dict1");
  addRequiredFile("dict2");
}
