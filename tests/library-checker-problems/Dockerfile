FROM ubuntu:22.10

RUN apt-get update && \
    apt-get install -y build-essential gcc g++ clang git python3-dev python3-pip ruby-full && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Setup python3 and pip
RUN ln -s /usr/bin/python3 /usr/bin/python
ENV PYTHON=python3
RUN pip install --upgrade --no-cache-dir 'pip>=23.1.2'

# Setup Library Checker Problems
# RUN git clone https://github.com/yosupo06/library-checker-problems.git
RUN git clone https://github.com/ryota2357/library-checker-problems.git && cd library-checker-problems && git switch patch-1
RUN cd library-checker-problems && \
    pip install -r requirements.txt
