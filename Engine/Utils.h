#include <numeric>
#include <vector>
#include <cstdarg>
#include <iostream>
#include <memory>
#include "Task.h"
#include "ECU.h"

/** This file is engine code of CPSim-Re engine
 * @file RUBIS_Util.h
 * @class 
 * @author Seonghyeon Park
 * @date 2020-03-31
 * @brief Codes for Engine-RUBISUtil
 * This is for utilities of our laboratoy.
 * This functions are based on inline styles on C++ which is extern style of C . 
*/

namespace utils
{
    inline int hyper_period = 0;
    inline int elapsed_time = 0;
    inline int simulatorPC_performance = 3000;
    unsigned int ecu_counter =0;

    int greatest_common_divider(int a, int b);
    int least_common_multiple(int a, int b);
    int least_common_multiple_array(int argc, int* args);
}

namespace vectors
{
    std::vector<std::shared_ptr<ECU>> ecu_vector;
    std::vector<std::shared_ptr<Task>> task_vector;
}