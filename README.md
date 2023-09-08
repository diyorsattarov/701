markdown

# Twitch Stream Record in C++

## Purpose

The purpose of this C++ project is to provide a tool for fetching the live status of a Twitch streamer and initiating the recording of their live stream. With this application, you can easily monitor whether a specific Twitch streamer is currently live and automatically start recording their stream for later viewing. Whether you're an avid gamer, content creator, or simply interested in capturing Twitch streams, this project simplifies the process of stream management and recording.

## Features

- Checks if user is streaming
- Records desktop if they are live

## Prerequisites

Before you begin, ensure you have met the following requirements:

- CMake (minimum version 3.2)
- C++ compiler (supporting C++11 or later)
- Boost/Beast
- spdlog
- googletest
- nholmman/json
## Getting Started
```
git clone https://github.com/diyooor/cpp-stream-record
cmake .
cmake --build .
./test/bin/test_main.exe
```
## Testing
```
admin at ~/workspace/scratch/cpp-stream-record $ ./test/bin/test_main.exe
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from MyTestFixture
[ RUN      ] MyTestFixture.TestIsUserLive
[2023-09-07 20:58:14.586] [info] Welcome to spdlog!
[2023-09-07 20:58:15.115] [info] Token Response status code: 200
[2023-09-07 20:58:15.116] [info] Token Response body: {"access_token":"35gvw1iqwvvrkpstby0f3hmxw2xqxb","expires_in":5382977,"token_type":"bearer"}

[2023-09-07 20:58:15.117] [info] Access token: 35gvw1iqwvvrkpstby0f3hmxw2xqxb
[2023-09-07 20:58:15.384] [info] Response status code: 200
[2023-09-07 20:58:15.384] [info] Response body: {"data":[{"id":"40595437703","user_id":"52769526","user_login":"cruciie","user_name":"CruciIe","game_id":"21779","game_name":"League of Legends","type":"live","title":"KR CHALL SOLOQ BEST EZREAL MID IN THE WORLD WE HAVE VOD POGGERS !disc !coaching","viewer_count":68,"started_at":"2023-09-07T22:55:37Z","language":"en","thumbnail_url":"https://static-cdn.jtvnw.net/previews-ttv/live_user_cruciie-{width}x{height}.jpg","tag_ids":[],"tags":["Autistic","Educational","Coaching","English","Reformed","IncrediblyPoor","LGBT","Korea","KRServer"],"is_mature":true}],"pagination":{"cursor":"eyJiIjp7IkN1cnNvciI6ImV5SnpJam8yT0M0ek16STRNemcxT0RrMk16VTROeXdpWkNJNlptRnNjMlVzSW5RaU9uUnlkV1Y5In0sImEiOnsiQ3Vyc29yIjoiIn19"}}
[2023-09-07 20:58:15.385] [info] User is live!
ffmpeg version 6.0 Copyright (c) 2000-2023 the FFmpeg developers
  built with gcc 13.1.0 (Rev6, Built by MSYS2 project)
  configuration: --prefix=/mingw64 --target-os=mingw32 --arch=x86_64 --cc=gcc --cxx=g++ --disable-debug --disable-stripping --disable-doc --enable-dxva2 --enable-d3d11va --enable-fontconfig --enable-frei0r --enable-gmp --enable-gnutls --enable-gpl --enable-iconv --enable-libaom --enable-libass --enable-libbluray --enable-libcaca --enable-libdav1d --enable-libfreetype --enable-libfribidi --enable-libgme --enable-libgsm --enable-libmodplug --enable-libmp3lame --enable-libopencore_amrnb --enable-libopencore_amrwb --enable-libopenjpeg --enable-libopus --enable-libplacebo --enable-librsvg --enable-librtmp --enable-libssh --enable-libsoxr --enable-libspeex --enable-libsrt --enable-libtheora --enable-libvidstab --enable-libvorbis --enable-libx264 --enable-libx265 --enable-libxvid --enable-libvpx --enable-libwebp --enable-libxml2 --enable-libzimg --enable-openal --enable-pic --enable-postproc --enable-runtime-cpudetect --enable-swresample --enable-version3 --enable-vulkan --enable-zlib --enable-librav1e --enable-libsvtav1 --enable-libmfx --enable-amf --enable-nvenc --logfile=config.log --enable-shared
  libavutil      58.  2.100 / 58.  2.100
  libavcodec     60.  3.100 / 60.  3.100
  libavformat    60.  3.100 / 60.  3.100
  libavdevice    60.  1.100 / 60.  1.100
  libavfilter     9.  3.100 /  9.  3.100
  libswscale      7.  1.100 /  7.  1.100
  libswresample   4. 10.100 /  4. 10.100
  libpostproc    57.  1.100 / 57.  1.100
[gdigrab @ 000002579b6adcc0] Capturing whole desktop as 1920x1080x32 at (0,0)
[gdigrab @ 000002579b6adcc0] Stream #0: not enough frames to estimate rate; consider increasing probesize
Input #0, gdigrab, from 'desktop':
  Duration: N/A, start: 1694138295.461322, bitrate: 3981337 kb/s
  Stream #0:0: Video: bmp, bgra, 1920x1080, 3981337 kb/s, 60 fps, 1000k tbr, 1000k tbn
Stream mapping:
  Stream #0:0 -> #0:0 (bmp (native) -> h264 (libx264))
Press [q] to stop, [?] for help
[libx264 @ 000002579b6fedc0] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 000002579b6fedc0] profile High 4:4:4 Predictive, level 4.2, 4:4:4, 8-bit
[libx264 @ 000002579b6fedc0] 264 - core 164 r3107M a8b68eb - H.264/MPEG-4 AVC codec - Copyleft 2003-2023 - http://www.videolan.org/x264.html - options: cabac=1 ref=3 deblock=1:0:0 analyse=0x3:0x113 me=hex subme=7 psy=1 psy_rd=1.00:0.00 mixed_ref=1 me_range=16 chroma_me=1 trellis=1 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=4 threads=18 lookahead_threads=3 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=2 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc_lookahead=40 rc=crf mbtree=1 crf=23.0 qcomp=0.60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1.40 aq=1:1.00
Output #0, mp4, to 'stream_record.mp4':
  Metadata:
    encoder         : Lavf60.3.100
  Stream #0:0: Video: h264 (avc1 / 0x31637661), yuv444p(tv, progressive), 1920x1080, q=2-31, 60 fps, 15360 tbn
    Metadata:
      encoder         : Lavc60.3.100 libx264
    Side data:
      cpb: bitrate max/min/avg: 0/0/0 buffer size: 0 vbv_delay: N/A
frame= 1800 fps= 33 q=-1.0 Lsize=   10705kB time=00:00:29.95 bitrate=2928.1kbits/s speed=0.557x    
video:10683kB audio:0kB subtitle:0kB other streams:0kB global headers:0kB muxing overhead: 0.204170%
[libx264 @ 000002579b6fedc0] frame I:8     Avg QP:20.15  size:213740
[libx264 @ 000002579b6fedc0] frame P:502   Avg QP:23.26  size: 15002
[libx264 @ 000002579b6fedc0] frame B:1290  Avg QP:29.48  size:  1316
[libx264 @ 000002579b6fedc0] consecutive B-frames:  2.3%  5.3%  3.5% 88.9%
[libx264 @ 000002579b6fedc0] mb I  I16..4: 22.2% 46.2% 31.6%
[libx264 @ 000002579b6fedc0] mb P  I16..4:  1.9%  4.3%  1.4%  P16..4:  9.0%  2.1%  1.1%  0.0%  0.0%    skip:80.0%
[libx264 @ 000002579b6fedc0] mb B  I16..4:  0.2%  0.2%  0.0%  B16..8:  7.4%  0.4%  0.1%  direct: 0.1%  skip:91.6%  L0:34.2% L1:64.2% BI: 1.6%
[libx264 @ 000002579b6fedc0] 8x8 transform intra:54.2% inter:82.5%
[libx264 @ 000002579b6fedc0] coded y,u,v intra: 41.8% 22.8% 21.0% inter: 1.4% 0.6% 0.6%
[libx264 @ 000002579b6fedc0] i16 v,h,dc,p: 26% 47%  9% 18%
[libx264 @ 000002579b6fedc0] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 19% 19% 27%  6%  6%  6%  6%  5%  7%
[libx264 @ 000002579b6fedc0] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 28% 31% 14%  4%  5%  5%  5%  4%  5%
[libx264 @ 000002579b6fedc0] Weighted P-Frames: Y:0.0% UV:0.0%
[libx264 @ 000002579b6fedc0] ref P L0: 61.8% 16.5% 16.5%  5.1%
[libx264 @ 000002579b6fedc0] ref B L0: 86.8% 11.5%  1.8%
[libx264 @ 000002579b6fedc0] ref B L1: 95.3%  4.7%
[libx264 @ 000002579b6fedc0] kb/s:2917.12
[2023-09-07 20:59:09.403] [info] Recording completed successfully.
[       OK ] MyTestFixture.TestIsUserLive (54994 ms)
[----------] 1 test from MyTestFixture (54999 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (55011 ms total)
[  PASSED  ] 1 test.
```

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to create a pull request.
License

This project is licensed under the MIT License. See the LICENSE file for details.