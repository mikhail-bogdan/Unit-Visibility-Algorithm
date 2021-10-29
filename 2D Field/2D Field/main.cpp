#include <vector>
#include <thread>
#include <fstream>

#include "Unit.h"
#include "LineFunctions.h"
#include "Quaternion.h"


void CalculateUnitView(const std::vector<Unit>& units, int unitStartIndex, int indexStep, std::vector<int>& nums)
{
	for (int i = unitStartIndex; i < units.size(); i += indexStep)
	{
		nums[i] = 0;

		const Unit* unit = &units[i];
		Vector2 leftLineVector = unit->GetLeftDirection();
		Vector2 rightLineVector = unit->GetRightDirection();

		for (int j = 0; j < units.size(); j++)
		{
			if (i == j) continue;

			Vector2 anotherUnitPos = units[j].GetPosition() - unit->GetPosition();

			if (LineFunctions::IsPointOnRightOfLine(leftLineVector, anotherUnitPos)
				&& LineFunctions::IsPointOnLeftOfLine(rightLineVector, anotherUnitPos)
				&& anotherUnitPos.SqrMagnitude() <= unit->GetSqrViewDistance())
			{
				nums[i] ++;
			}
		}
	}
}

int main()
{
	const int numThreads = 3;
	UnitSettings settings(135.5f, 2);

	std::ifstream in("units.txt");

	int unitsCount;
	in >> unitsCount;

	std::vector<Unit> units;
	std::vector<int> nums(unitsCount);

	for (int i = 0; i < unitsCount; i++)
	{
		Vector2 position;
		Vector2 viewDirection;
		in >> position.x;
		in >> position.y;
		in >> viewDirection.x;
		in >> viewDirection.y;

		units.push_back(Unit(position, viewDirection, settings));
	}

	in.close();
	
	std::thread threads[numThreads];

	for (int i = 0; i < numThreads; i++)
		threads[i] = std::thread(CalculateUnitView, std::ref(units), i, numThreads, std::ref(nums));

	for (int i = 0; i < numThreads; i++)
		threads[i].join();

	std::ofstream out("units_visibility.txt");

	for (int i = 0; i < nums.size(); i++)
	{
		out << nums[i] << "\n";
	}

	out.flush();
	out.close();

	return 0;
}
