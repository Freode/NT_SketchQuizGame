#pragma once

void setIDInSocket(char cilentID[], SOCKETINFO* ptr); // ID ���Ͽ� ����ϴ� �Լ�.
bool CheckIDDuplication(int nTotalSockets, SOCKETINFO* SocketInfoArray[], char id[]);