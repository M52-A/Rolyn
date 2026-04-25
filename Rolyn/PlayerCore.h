#pragma once

#include <winrt/Windows.Media.Playback.h>

namespace Player
{
	class PlayerCore
	{
		winrt::Windows::Media::Playback::MediaPlayer player{ nullptr };

	public:
		winrt::Windows::Foundation::IAsyncAction Load(std::wstring path);
	};
}

