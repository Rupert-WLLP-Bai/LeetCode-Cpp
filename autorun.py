import os
import subprocess
import time
import logging

# 配置日志记录
logging.basicConfig(level=logging.INFO, format='[%(levelname)s] %(message)s')

def log_file_info(file_path):
    file_time = os.path.getmtime(file_path)
    formatted_time = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(file_time))
    logging.info(f'File: {file_path}, Last Modified: {formatted_time}')

# 进入 build 目录
os.chdir('build')
logging.info('Changed directory to build')

# 执行 cmake ..
logging.info('Running cmake ..')
# 判断平台 如果是Windows系统，使用cmake .. -G "Ninja"，否则使用cmake ..
if os.name == 'nt':
    logging.info('Detected Windows system, using Ninja generator')
    subprocess.run(['cmake', '..', '-G', 'Ninja'])
else:
    logging.info('Detected non-Windows system, using default generator')
    subprocess.run(['cmake', '..'])

# 执行 make
logging.info('Running make')
if os.name == 'nt':
    subprocess.run(['ninja','-j16'])
else:
    subprocess.run(['make', '-j16'])

# 找到最新生成或修改的二进制文件
latest_time = 0
latest_binary = None

for root, dirs, files in os.walk('.'):
    for file in files:
        file_path = os.path.join(root, file)
        if os.access(file_path, os.X_OK):  # 检查文件是否可执行
            file_time = os.path.getmtime(file_path)
            if file_time > latest_time:
                latest_time = file_time
                latest_binary = file_path
                log_file_info(file_path)

# 运行二进制文件
if latest_binary:
    logging.info(f'Running {latest_binary}')
    subprocess.run([latest_binary])
else:
    logging.info('No executable file found')
