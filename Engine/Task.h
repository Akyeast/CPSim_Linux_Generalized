/** �� ������ Task ����� �ǻ��ڵ� �ۼ� �����Դϴ�.
 *  ���������� ���� �����������, ���´� �Ʒ��� ���� ������
 *  @file Task.cpp
 *  @brief Pseudo Codes for Engine-Task
 *  @page Task
 *  @author Seonghyeon Park
 *  @date 2020-02-18
 *  @section Logic
 *  Task ������ ������ ����.
 *  1. Specification ��� ���� �� ������ ���� �ް� �ƴ� ���, ���� ���
 *  2. Specification�� �ʿ��� �ν��Ͻ� ������ ���� �� CAN �������̽� ��� ����
 *  3.
 *
 *
 */
#include <cstdio>

/// @class Task
class Task
{
public:
	virtual void Update() = 0;
	virtual bool ShouldWeExecute() = 0;

	virtual ~Task()
	{
		printf("Destroyed\n");
	}
};