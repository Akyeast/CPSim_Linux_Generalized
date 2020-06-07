#ifndef UTILS_H__
#define UTILS_H__

#include <numeric>
#include <vector>
#include <cstdarg>
#include <iostream>
#include <memory>
#include <signal.h>
#include <thread>
#include <algorithm>

#include "Task.h"
#include "Job.h"
#include "ECU.h"
#include "CAN_message.h"
#include "Logger.h"

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
    inline std::string file_path = "/home/";
    inline std::string null_path = "";
    inline int hyper_period = 0;
    inline double current_time = 0; //simulation time(us)
    inline int number_of_ECUs = 0;
    inline int number_of_tasks = 0;
    inline int simulatorPC_performance = 3000;
    inline double simple_mapping_function = 0.3;
    inline double simple_gpu_mapping_function = 0.1;
    inline bool execute_gpu_jobs_on_cpu = false; // Used for comparing CPU vs GPU simulatability increase.
    inline bool enable_gpu_scheduling = false;
    inline int gpu_task_percentage = 30; // 30% of tasks will be GPU tasks.
    inline int simulatorGPU_performance = 12000;
    inline unsigned int ecu_counter = 0;
    inline bool is_experimental = true;
    

    int greatest_common_divider(int a, int b);
    int least_common_multiple(int a, int b);
    int least_common_multiple_array(std::vector<std::shared_ptr<Task>>& task_set);
    int calculate_hyper_period(std::vector<std::shared_ptr<Task>>& task_set);
    bool compare(std::shared_ptr<Job> pred, std::shared_ptr<Job> succ);
    bool first_release(std::shared_ptr<Job> pred, std::shared_ptr<Job> succ);
    void exit_simulation(int signo);
    void insert_can_msg(std::shared_ptr<CAN_message> input);
}

namespace vectors
{
    inline std::vector<std::shared_ptr<Job> > job_vector_of_simulator;
    inline std::vector<std::vector<std::shared_ptr<Job>>> job_vectors_for_each_task;
    inline std::vector<std::vector<std::shared_ptr<Job>>> job_vectors_for_each_ECU;
    inline std::vector<std::shared_ptr<ECU> > ecu_vector;
    inline std::vector<std::shared_ptr<Task>> task_vector;
    inline std::vector<std::shared_ptr<CAN_message> > can_msg_vector;
}

namespace global_object
{
    inline std::shared_ptr<Logger> logger;
    inline std::shared_ptr<std::thread> logger_thread;
}

#endif