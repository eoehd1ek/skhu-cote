#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

// 장르는 장르명
// 재생 횟수는 각 곡별 재생 횟수.
vector<int> solution(vector<string> genres, vector<int> plays) {
    // 장르별 총 재생 횟수를 만든다.
    unordered_map<string, int> genre_play_count;
    for (int i = 0; i < genres.size(); ++i) {
        genre_play_count[genres[i]] += plays[i];
    }

    // 총 재생 횟수가 많은 순서대로 장르를 정렬한다.
    // note : 모든 장르는 재생된 횟수가 다릅니다.
    vector<pair<int, string>> sorted_genres;
    for (const auto [genre, play_count] : genre_play_count) {
        sorted_genres.push_back({play_count, genre});
    }
    sort(sorted_genres.rbegin(), sorted_genres.rend());

    // 장르별 [플레이 횟수, 곡 번호] 배열을 만들어 저장한다.
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    for (int i = 0; i < genres.size(); ++i) {
        genre_songs[genres[i]].push_back({plays[i], i});
    }

    // 정렬된 장르 순서대로 각 2곡씩 선택하여 vector에 모아 반환한다.
    // vector에 모아 반환한다.
    vector<int> result;
    for (const auto& [play_count, genre] : sorted_genres) {
        vector<pair<int, int>>& songs = genre_songs[genre];
        // 가장 많이 재생된 곡, id가 작은 순서로 정렬한다.
        sort(songs.begin(), songs.end(), compare);

        int end_index = min(2, (int)songs.size());
        for (int i = 0; i < end_index; ++i) {
            result.push_back(songs[i].second);
        }
    }

    return result;
}
