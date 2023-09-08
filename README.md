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

Response when a user is not streaming
```
admin at ~/workspace/scratch/cpp-stream-record $ ./test/bin/test_main.exe
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from MyTestFixture
[ RUN      ] MyTestFixture.TestIsUserLive
[2023-09-07 21:50:21.613] [info] Welcome to spdlog!
[2023-09-07 21:50:22.169] [info] Token Response status code: 200
[2023-09-07 21:50:22.169] [info] Token Response body: {"access_token":"9f075lx09upj0i3mhx56qn3mb9n8lp","expires_in":5360524,"token_type":"bearer"}

[2023-09-07 21:50:22.170] [info] Access token: 9f075lx09upj0i3mhx56qn3mb9n8lp
[2023-09-07 21:50:22.330] [info] Response status code: 200
[2023-09-07 21:50:22.330] [info] Response body: {"data":[],"pagination":{}}
[2023-09-07 21:50:22.331] [info] User is not live.
[       OK ] MyTestFixture.TestIsUserLive (873 ms)
[----------] 1 test from MyTestFixture (879 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (896 ms total)
[  PASSED  ] 1 test.
```

Response when the user is streaming
```
admin at ~/workspace/scratch/cpp-stream-record $ ./test/bin/test_main.exe
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from MyTestFixture
[ RUN      ] MyTestFixture.TestIsUserLive
[2023-09-07 21:52:28.709] [info] Welcome to spdlog!
[2023-09-07 21:52:29.209] [info] Token Response status code: 200
[2023-09-07 21:52:29.209] [info] Token Response body: {"access_token":"02h2rim3hphe1qmbw04f2p83mhhglo","expires_in":5580515,"token_type":"bearer"}

[2023-09-07 21:52:29.209] [info] Access token: 02h2rim3hphe1qmbw04f2p83mhhglo
[2023-09-07 21:52:29.541] [info] Response status code: 200
[2023-09-07 21:52:29.542] [info] Response body: {"data":[{"id":"42718801915","user_id":"786013513","user_login":"therealskybri","user_name":"therealskybri","game_id":"33214","game_name":"Fortnite","type":"live","title":"TRYING ON CLOTHES ;)","viewer_count":2399,"started_at":"2023-09-08T00:31:03Z","language":"en","thumbnail_url":"https://static-cdn.jtvnw.net/previews-ttv/live_user_therealskybri-{width}x{height}.jpg","tag_ids":[],"tags":["IRL","English","girl","pool","hottub","fortnite","sleep","edate","legos"],"is_mature":true}],"pagination":{"cursor":"eyJiIjp7IkN1cnNvciI6ImV5SnpJam95TXprNUxqa3lOVGMwT1RRek56ZzJOaXdpWkNJNlptRnNjMlVzSW5RaU9uUnlkV1Y5In0sImEiOnsiQ3Vyc29yIjoiIn19"}}
[2023-09-07 21:52:29.542] [info] User is live!
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
[gdigrab @ 0000019de6e3eec0] Capturing whole desktop as 1920x1080x32 at (0,0)
[gdigrab @ 0000019de6e3eec0] Stream #0: not enough frames to estimate rate; consider increasing probesize
Input #0, gdigrab, from 'desktop':
  Duration: N/A, start: 1694141549.798902, bitrate: 331778 kb/s
  Stream #0:0: Video: bmp, bgra, 1920x1080, 331778 kb/s, 5 fps, 1000k tbr, 1000k tbn
File 'stream_record.mp4' already exists. Overwrite? [y/N] y
Stream mapping:
  Stream #0:0 -> #0:0 (bmp (native) -> h264 (libx264))
Press [q] to stop, [?] for help
[libx264 @ 0000019de7a22a80] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0000019de7a22a80] profile High 4:4:4 Predictive, level 4.0, 4:4:4, 8-bit
[libx264 @ 0000019de7a22a80] 264 - core 164 r3107M a8b68eb - H.264/MPEG-4 AVC codec - Copyleft 2003-2023 - http://www.videolan.org/x264.html - options: cabac=1 ref=3 deblock=1:0:0 analyse=0x3:0x113 me=hex subme=7 psy=1 psy_rd=1.00:0.00 mixed_ref=1 me_range=16 chroma_me=1 trellis=1 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=4 threads=18 lookahead_threads=3 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=2 keyint=250 keyint_min=5 scenecut=40 intra_refresh=0 rc_lookahead=40 rc=crf mbtree=1 crf=23.0 qcomp=0.60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1.40 aq=1:1.00        
Output #0, mp4, to 'stream_record.mp4':
  Metadata:
    encoder         : Lavf60.3.100
  Stream #0:0: Video: h264 (avc1 / 0x31637661), yuv444p(tv, progressive), 1920x1080, q=2-31, 5 fps, 10240 tbn
    Metadata:
      encoder         : Lavc60.3.100 libx264
    Side data:
      cpb: bitrate max/min/avg: 0/0/0 buffer size: 0 vbv_delay: N/A
frame=  150 fps=5.2 q=-1.0 Lsize=    1324kB time=00:00:29.40 bitrate= 369.0kbits/s speed=1.02x      
video:1322kB audio:0kB subtitle:0kB other streams:0kB global headers:0kB muxing overhead: 0.196026%
[libx264 @ 0000019de7a22a80] frame I:1     Avg QP:12.77  size:371409
[libx264 @ 0000019de7a22a80] frame P:40    Avg QP:14.80  size: 18966
[libx264 @ 0000019de7a22a80] frame B:109   Avg QP:19.54  size:  2043
[libx264 @ 0000019de7a22a80] consecutive B-frames:  2.0%  1.3%  6.0% 90.7%
[libx264 @ 0000019de7a22a80] mb I  I16..4: 33.8% 28.2% 38.0%
[libx264 @ 0000019de7a22a80] mb P  I16..4:  1.6%  1.0%  1.6%  P16..4:  1.9%  0.3%  0.3%  0.0%  0.0%    skip:93.3%
[libx264 @ 0000019de7a22a80] mb B  I16..4:  0.2%  0.1%  0.1%  B16..8:  1.8%  0.1%  0.1%  direct: 0.0%  skip:97.5%  L0:48.3% L1:50.3% BI: 1.4%
[libx264 @ 0000019de7a22a80] 8x8 transform intra:23.4% inter:44.8%
[libx264 @ 0000019de7a22a80] coded y,u,v intra: 28.1% 21.1% 20.4% inter: 0.3% 0.2% 0.1%
[libx264 @ 0000019de7a22a80] i16 v,h,dc,p: 51% 47%  1%  0%
[libx264 @ 0000019de7a22a80] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 52% 12% 34%  0%  0%  0%  0%  0%  1%
[libx264 @ 0000019de7a22a80] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 32% 33% 16%  2%  3%  3%  4%  2%  5%
[libx264 @ 0000019de7a22a80] Weighted P-Frames: Y:0.0% UV:0.0%
[libx264 @ 0000019de7a22a80] ref P L0: 55.8%  6.5% 25.9% 11.8%
[libx264 @ 0000019de7a22a80] ref B L0: 70.5% 27.8%  1.7%
[libx264 @ 0000019de7a22a80] ref B L1: 96.5%  3.5%
[libx264 @ 0000019de7a22a80] kb/s:360.72
[2023-09-07 21:53:01.643] [info] Recording completed successfully.
[       OK ] MyTestFixture.TestIsUserLive (33096 ms)
[----------] 1 test from MyTestFixture (33103 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (33120 ms total)
[  PASSED  ] 1 test.
```

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to create a pull request.
License

This project is licensed under the MIT License. See the LICENSE file for details.