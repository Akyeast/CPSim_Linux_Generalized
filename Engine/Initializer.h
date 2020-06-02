#ifndef INITIALIZER_H__
#include <stdio.h>
#include <pcan.h>
#include <libpcan.h>
#include <thread>

#include "Specifier.h"
#include "Utils.h"
#include "Logger.h"


/** This file is engine code of CPSim-Re engine
 * @file Initializer.h
 * @author Seonghyeon Park
 * @date 2020-03-31
 * @class Initializer
 * @brief Codes for Engine-Initializer.\n
 * The Initializer is responsible for initializing entire objects of 
 * simulator engine.
*/

class Initializer
{
private:
public:
    /**
     * Constructor & Destructor
    */
    Initializer();
    ~Initializer();

    int execution_time_mapping_function();
    int can_interface_initalizer(int num_channel);
    int parsing_specificated_information();
    
    void random_task_generator(double, double, int); // this function is for experiments.
    void random_ecu_generator(int); // this function is for experiments.
    void random_producer_consumer_generator();

    void set_simulatorPC_performance();
    void initialize(std::string location);
};

#endif
