FROM alpine:3.16.2 AS builder
LABEL maintainer="Pegasust <pegasucksgg@gmail.com>"
VOLUME "/project"
WORKDIR "/project"

# Essentials
RUN apk update && apk upgrade && apk --update add \
    gcc g++ build-base cmake bash libstdc++ cppcheck python3 py-pip git

# Conan
RUN pip install conan

# Additional dependencies
RUN apk --update add curl-dev boost-dev

# Clean up the cache
RUN rm -rf /var/cache/apk

ENTRYPOINT ["bash", "-c"]
# Copy our project file inside
COPY ./project /project
# TODO: Build here
RUN cmake -S all -B build && cmake --build build

# Main runtime
FROM alpine:3.16.2
LABEL maintainer="Pegasust <pegasucksgg@gmail.com>"
VOLUME "/root"
WORKDIR "/root"

# TODO: Add runtime dependencies here
RUN apk update && apk upgrade && apk --update add curl boost

COPY --from=builder /project/build /root


