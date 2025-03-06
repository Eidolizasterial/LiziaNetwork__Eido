#pragma once

#include <vector>


namespace ln
{
	struct IncomingData
	{
		unsigned int _incoming_id = 0;
		float _data = 0;
	};

	struct IncomingLayerData
	{
		std::vector<IncomingData> _IncomingData_s;
	};

	struct IncomingSegmentData
	{
		unsigned int _incoming_segment_id = 0;
		IncomingLayerData _IncomingLayerData;
	};
}