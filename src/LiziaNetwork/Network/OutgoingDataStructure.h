#pragma once

#include <vector>

struct OutgoingData
{
	unsigned int _outgoing_id = 0;
	float _data = 0;
};

struct OutgoingLayerData
{
	std::vector<OutgoingData> _OutgoingData_s;
};

struct OutgoingSegmentData
{
	unsigned int _oudgoing_segment_data = 0;
	OutgoingLayerData _OutgoingLayerData;
};