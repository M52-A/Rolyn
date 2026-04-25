#include "pch.h"
#include "PlayerCore.h"

#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Media.Core.h>


namespace Player
{
	winrt::Windows::Foundation::IAsyncAction PlayerCore::Load(std::wstring path)
	{
		if (!player)
			player = winrt::Windows::Media::Playback::MediaPlayer();
		winrt::Windows::Storage::StorageFile file = co_await winrt::Windows::Storage::StorageFile::GetFileFromPathAsync(path);
		player.Source(winrt::Windows::Media::Core::MediaSource::CreateFromStorageFile(file));
	}
}