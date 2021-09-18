/*
 *  Copyright (C) 2005-2021 Team Kodi (https://kodi.tv)
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "EpgGenre.h"

#include <string>
#include <vector>

#include <kodi/addon-instance/pvr/EPG.h>
#include <pugixml.hpp>

namespace iptvsimple
{
  namespace data
  {
    static const float STAR_RATING_SCALE = 10.0f;
    constexpr int DATESTRING_LENGTH = 8;

    class EpgEntry
    {
    public:
      int GetBroadcastId() const { return m_broadcastId; }
      void SetBroadcastId(int value) { m_broadcastId = value; }

      int GetChannelId() const { return m_channelId; }
      void SetChannelId(int value) { m_channelId = value; }

      int GetGenreType() const { return m_genreType; }
      void SetGenreType(int value) { m_genreType = value; }

      int GetGenreSubType() const { return m_genreSubType; }
      void SetGenreSubType(int value) { m_genreSubType = value; }

      int GetYear() const { return m_year; }
      void SetYear(int value) { m_year = value; }

      int GetStarRating() const { return m_starRating; }
      void SetStarRating(int value) { m_starRating = value; }

      int GetEpisodeNumber() const { return m_episodeNumber; }
      void SetEpisodeNumber(int value) { m_episodeNumber = value; }

      int GetEpisodePartNumber() const { return m_episodePartNumber; }
      void SetEpisodePartNumber(int value) { m_episodePartNumber = value; }

      int GetSeasonNumber() const { return m_seasonNumber; }
      void SetSeasonNumber(int value) { m_seasonNumber = value; }

      time_t GetStartTime() const { return m_startTime; }
      void SetStartTime(time_t value) { m_startTime = value; }

      time_t GetEndTime() const { return m_endTime; }
      void SetEndTime(time_t value) { m_endTime = value; }

      const std::string& GetFirstAired() const { return m_firstAired; }
      void SetFirstAired(const std::string& value) { m_firstAired = value; }

      const std::string& GetTitle() const { return m_title; }
      void SetTitle(const std::string& value) { m_title = value; }

      const std::string& GetEpisodeName() const { return m_episodeName; }
      void SetEpisodeName(const std::string& value) { m_episodeName = value; }

      const std::string& GetPlotOutline() const { return m_plotOutline; }
      void SetPlotOutline(const std::string& value) { m_plotOutline = value; }

      const std::string& GetPlot() const { return m_plot; }
      void SetPlot(const std::string& value) { m_plot = value; }

      const std::string& GetIconPath() const { return m_iconPath; }
      void SetIconPath(const std::string& value) { m_iconPath = value; }

      const std::string& GetGenreString() const { return m_genreString; }
      void SetGenreString(const std::string& value) { m_genreString = value; }

      const std::string& GetCast() const { return m_cast; }
      void SetCast(const std::string& value) { m_cast = value; }

      const std::string& GetDirector() const { return m_director; }
      void SetDirector(const std::string& value) { m_director = value; }

      const std::string& GetWriter() const { return m_writer; }
      void SetWriter(const std::string& value) { m_writer = value; }

      const std::string& GetCatchupId() const { return m_catchupId; }
      void SetCatchupId(const std::string& value) { m_catchupId = value; }

      bool IsNew() const { return m_new; }
      void SetNew(int value) { m_new = value; }

      bool IsPremiere() const { return m_premiere; }
      void SetPremiere(int value) { m_premiere = value; }

      void UpdateTo(kodi::addon::PVREPGTag& left, int iChannelUid, int timeShift, const std::vector<EpgGenre>& genres);
      bool UpdateFrom(const pugi::xml_node& channelNode, const std::string& id,
                      int start, int end, int minShiftTime, int maxShiftTime);

    private:
      bool SetEpgGenre(std::vector<EpgGenre> genreMappings);
      bool ParseEpisodeNumberInfo(std::vector<std::pair<std::string, std::string>>& episodeNumbersList);
      bool ParseXmltvNsEpisodeNumberInfo(const std::string& episodeNumberString);
      bool ParseOnScreenEpisodeNumberInfo(const std::string& episodeNumberString);

      int m_broadcastId;
      int m_channelId;
      int m_genreType;
      int m_genreSubType;
      int m_year;
      int m_starRating;
      int m_episodeNumber = EPG_TAG_INVALID_SERIES_EPISODE;
      int m_episodePartNumber = EPG_TAG_INVALID_SERIES_EPISODE;
      int m_seasonNumber = EPG_TAG_INVALID_SERIES_EPISODE;
      time_t m_startTime;
      time_t m_endTime;
      std::string m_firstAired;
      std::string m_title;
      std::string m_episodeName;
      std::string m_plotOutline;
      std::string m_plot;
      std::string m_iconPath;
      std::string m_genreString;
      std::string m_cast;
      std::string m_director;
      std::string m_writer;
      std::string m_catchupId;
      bool m_new = false;
      bool m_premiere = false;
    };
  } //namespace data
} //namespace iptvsimple
