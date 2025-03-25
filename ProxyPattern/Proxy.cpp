#include "Proxy.h"
#include <iostream>
#include <vector>

using namespace std;

void TVManager::renderVidioPage(int id)
{
	Video* video = Service->DownloadVideo(id);
	cout << "video: { id: " << video->info->id
		<< ", name: " << video->info->name
		<< ", size: " << video->info->size
		<< endl;
	cout << "Video: " << video->data << endl;
}

void TVManager::renderListPanel()
{
	vector<VideoInfo*> infos = Service->ListVideos();
	for (auto info : infos) {
		cout << "video: { id: " << info->id
			<< ", name: " << info->name
			<< ", size: " << info->size
			<< endl;
	}
}

void TVManager::reactOnUserInput()
{
	renderListPanel();
	int id;
	cin >> id;
	renderVidioPage(id);
}

ThirdPartyTVClass::~ThirdPartyTVClass()
{
	for (auto &video : Videos) {
		delete video;
		video = nullptr;
	}
	Videos.clear();
}

std::vector<VideoInfo*> ThirdPartyTVClass::ListVideos()
{
	vector<VideoInfo*> infos;
	for(const auto video: Videos)
	{
		infos.push_back(video->info);
	}
	return infos;
}

VideoInfo* ThirdPartyTVClass::GetVideoInfo(int id)
{
	for (auto video : Videos)
	{
		if (video->info->id == id)
			return video->info;
	}
	return nullptr;
}

Video* ThirdPartyTVClass::DownloadVideo(int id)
{
	for (auto video : Videos)
	{
		if (video->info->id == id)
			return video;
	}
	return nullptr;
}

void ThirdPartyTVClass::addVideo(int id, std::string name, double size, std::string data)
{
	Video* newVideo = new Video(id, name, size, data);
	Videos.push_back(newVideo);
}

std::vector<VideoInfo*> CachedTVClass::ListVideos()
{
	if (VideoInfos.empty()) {
		cout << "Caching VideoInfos" << endl;
		vector<VideoInfo*> Temp = Service->ListVideos();
		VideoInfos = Temp;
	}
	return VideoInfos;
}

VideoInfo* CachedTVClass::GetVideoInfo(int id)
{
	if (VideoInfos.empty()) {
		cout << "Caching VideoInfos" << endl;
		VideoInfos = Service->ListVideos();
	}
	for (auto info : VideoInfos) {
		if (info->id == id) {
			return info;
		}
	}
	return nullptr;
}

Video* CachedTVClass::DownloadVideo(int id)
{
	for (auto video: CachedVideos){
		if (video->info->id == id) {
			cout << "Cached Video: " << id << "!" << endl;
			return video;
		}
	}
	Video* newVideo = Service->DownloadVideo(id);
	if (newVideo != nullptr)
		CachedVideos.push_back(newVideo);
	return newVideo;
}
