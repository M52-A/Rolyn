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

	void PlayerCore::Play()
	{
		player.Play();
	}

	void PlayerCore::Pause()
	{
		player.Pause();
	}

	winrt::Windows::Media::Playback::MediaPlayerState PlayerCore::TogglePlay()
	{
		if (!player)
			return winrt::Windows::Media::Playback::MediaPlayerState::Stopped;
		if (player.CurrentState() != winrt::Windows::Media::Playback::MediaPlayerState::Playing)
		{
			Play();
			return winrt::Windows::Media::Playback::MediaPlayerState::Playing;
		}
		Pause();
		return winrt::Windows::Media::Playback::MediaPlayerState::Paused;
	}
}