#pragma once

// Ŭ���̾�Ʈ ��� ����Ʈ �ڵ�
static HWND g_hListView;
// ������ Ŭ���̾�Ʈ�� �ε����� ������ ���� ����
static int g_selectedIndex = -1;

void InitializeListView(HWND hWnd);
void AddClientToListView(int port, _TCHAR* id);
void DisplayClientList();
void RemoveClientFromListView(int port);