
class Redis:
    pass


class RateLimitingStrategy:

    REFRESH_TIME = 60
    MAX_REQUESTS = 5

    def __init__(self) -> None:
        self.redis = Redis()
        

    def get_unique_identifier(request):
        return request.get("user_id")
    
    def remove_timestamps(self, request, timestamps):
        redis_key = self.get_redis_key(self.get_unique_identifier(request))

        self.redis.remove_from_set(redis_key, timestamps)
        return True

    def is_request_allowed(self, request):
        user_id = self.get_unique_identifier()

        current_timestamp = self.get_timestamp()

        self.add_request_timestamp_redis(request)

        timestamps = self.get_requests_timestamps(request)

        if len(timestamps) < self.MAX_REQUESTS:
            return True
        
        to_be_removed_timestamps = []

        for timestamp in timestamps:
            if timestamp < current_timestamp - self.REFRESH_TIME:
                to_be_removed_timestamps.append(timestamp)
            else:
                break

        self.remove_timestamps(request, to_be_removed_timestamps)
            
        return len(timestamps) - len(to_be_removed_timestamps) <= self.MAX_REQUESTS


        

    

class RateLimiter:

    def __init__(self, strategy) -> None:
        self.strategy = strategy

    def send_req(request):
        pass

    def send_api_rate_limited(self):
        pass

    def is_request_allowed(self, request):
        if self.strategy.is_request_allowed(request):
            self.send_req(request)
        else:
            return self.send_api_rate_limited()
