#pragma once

// Ŭ���̾�Ʈ ��� view �ڵ�
static HWND g_hListView;
// ������ Ŭ���̾�Ʈ�� �ε����� ������ ���� ����
static int g_selectedIndex = -1;
// �ӽ� ���� ����
static SOCKET tmp_ClientSock[10];

void InitializeListView(HWND hWnd);
void AddClientSocketAndIndex(int index, SOCKET sock);
void AddClientToListView(int port, _TCHAR* id, SOCKET sock);
void DisplayClientList();
void RemoveClientFromListView(int port);
void RemoveClientFromListViewAndSock(int index);