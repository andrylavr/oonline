#include "TaskHandler.h"

TaskHandler TaskHandler::_instance;
TaskHandler::TaskHandler(void) : pool(4)
{
}

TaskHandler::~TaskHandler(void)
{
}
