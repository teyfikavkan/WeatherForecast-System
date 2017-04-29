#pragma once
#include "DayA.h"

namespace MyFunctions{
	    

	bool is_empty(ifstream& pFile)
	{
		return pFile.peek() == std::ifstream::traits_type::eof();
	}


	


};


