#include "Logger.h"
#include "Utils.h"

#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <climits>
#include <mutex>

/**
 *  This file is the cpp file for the Logger class.
 *  @file Logger.cpp
 *  @brief cpp file for Engine-Logger
 *  @author Seonghyeon Park
 *  @date 2020-03-31
 */


/**
 * @fn Logger::Logger()
 * @brief the function of basic constructor of Logger
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  - None
 * @param none
 * @return none
 * @bug none
 * @warning none
 * @todo none
 */
Logger::Logger()
{
    
}

/**
 * @fn Logger::~Logger()
 * @brief the function of basic destructor of Logger
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  - None
 * @param none
 * @return none
 * @bug none
 * @warning none
 * @todo none
 */
Logger::~Logger()
{

}

/**
 * @fn void start_logging()
 * @brief this function starts the logging of simulation events
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  - None
 * @param none
 * @return none
 * @bug none
 * @warning none
 * @todo none
 */

void Logger::set_schedule_log_info(std::vector<std::shared_ptr<Task>>& task_vector)
{
    std::cout << "Logging starts" << std::endl;
    std::ofstream scheduling_log;
    scheduling_log.open(utils::cpsim_path + "/Log/scheduling.log", std::ios::out);     
    std::string contents = "";
    for(int idx = 0; idx < task_vector.size(); idx++)
    {
        contents += "ECU" + std::to_string(task_vector.at(idx)->get_ECU()->get_ECU_id())+ ": " + task_vector.at(idx)->get_task_name();
        if(idx == task_vector.size() - 1)
            contents += "\n";
        else
        {
            contents += ", ";
        }
         
    }
    scheduling_log.write(contents.c_str(), contents.size());
    scheduling_log.close();
    
}
void Logger::start_logging()
{
    utils::simulator_elapsed_time = 0;

    std::ofstream scheduling_log;
    while (utils::current_time < utils::simulation_termination_time)
    {
        scheduling_log.open(utils::cpsim_path + "/Log/scheduling.log", std::ios::app);    
        utils::mtx_data_log.lock();
        if(global_object::diagram_vector.size() > 10)
        {
            int min_idx = 0;
            std::shared_ptr<DiagramData> current_data = global_object::diagram_vector.front();
            for (int idx = 0; idx < global_object::diagram_vector.size(); idx ++)
            {
                if(current_data->get_time() >  global_object::diagram_vector.at(idx)->get_time())
                {
                    current_data = global_object::diagram_vector.at(idx);
                    min_idx = idx;
                }
            }
            
            global_object::diagram_vector.erase(global_object::diagram_vector.begin() + min_idx);
            scheduling_log.write(current_data->get_data().c_str(), current_data->get_data().size());
        }
        scheduling_log.close();
        if(global_object::diagram_vector.size() > 100)
            global_object::diagram_vector.clear();
        utils::mtx_data_log.unlock();    
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }    
    
}
