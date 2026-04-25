#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.Storage.Pickers.h>
#include <shobjidl.h>
#include <microsoft.ui.xaml.window.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::Rolyn::implementation
{
	MainWindow::MainWindow()
	{
		ExtendsContentIntoTitleBar(true);
	}

	int32_t MainWindow::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainWindow::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	winrt::Windows::Foundation::IAsyncAction MainWindow::OpenFile_Click(winrt::Windows::Foundation::IInspectable const &sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const &e)
	{
		OpenFile().IsEnabled(false);

		auto picker = winrt::Windows::Storage::Pickers::FileOpenPicker();
		auto windowNative = this->m_inner.as<::IWindowNative>();
		HWND hwnd = nullptr;
		windowNative->get_WindowHandle(&hwnd);
		picker.as<IInitializeWithWindow>()->Initialize(hwnd);
		picker.FileTypeFilter().Append(L".mp3");
		picker.CommitButtonText(L"Open ...");
		picker.SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId::MusicLibrary);
		picker.ViewMode(winrt::Windows::Storage::Pickers::PickerViewMode::List);

		auto file = co_await picker.PickSingleFileAsync();
		if (file)
			core.Load(file.Path().c_str());

		OpenFile().IsEnabled(true);
	}
}
