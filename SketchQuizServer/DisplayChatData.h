#pragma once

// ä�� ������ view �ڵ�
static HWND g_hChatListView;

void InitializeChatListView(HWND hWnd);
void AddChatMessageToListView(_TCHAR* id, _TCHAR* message);
void DisplayChatList();