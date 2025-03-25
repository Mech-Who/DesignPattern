#pragma once

#ifndef __PROXY_H__
#define __PROXY_H__

#include <string>
#include <vector>

struct VideoInfo {
	int id;
	std::string name;
	double size;
};

struct Video 
{
	Video(int id, std::string name, double size, std::string data) : data(data) {
		info = new VideoInfo(id, name, size);
	}
	~Video() { if (info != nullptr) delete info; }
	VideoInfo* info;
	std::string data;
};

struct ThirdPartyTVLib;

struct TVManager
{
	TVManager() = delete;
	TVManager(ThirdPartyTVLib* service) : Service(service) {}
	void renderVidioPage(int id);
	void renderListPanel();
	void reactOnUserInput();
private:
	ThirdPartyTVLib* Service;
};

struct ThirdPartyTVLib
{
	virtual ~ThirdPartyTVLib() {}
	virtual std::vector<VideoInfo*> ListVideos() = 0;
	virtual VideoInfo* GetVideoInfo(int id) = 0;
	virtual Video* DownloadVideo(int id) = 0;
};

struct ThirdPartyTVClass : public ThirdPartyTVLib
{
	~ThirdPartyTVClass();
	std::vector<VideoInfo*> ListVideos() override;
	VideoInfo* GetVideoInfo(int id) override;
	Video* DownloadVideo(int id) override;
	void addVideo(int id, std::string name, double size, std::string data);
private:
	std::vector<Video*> Videos;
};

struct CachedTVClass : public ThirdPartyTVLib
{
	CachedTVClass(ThirdPartyTVClass* service) : Service(service) {}
	std::vector<VideoInfo*> ListVideos() override;
	VideoInfo* GetVideoInfo(int id) override;
	Video* DownloadVideo(int id) override;
private:
	std::vector<Video*> CachedVideos;
	std::vector<VideoInfo*> VideoInfos;
	ThirdPartyTVLib* Service;
};

#endif // __PROXY_H__
